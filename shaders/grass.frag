#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// position of the object
in vec3 crntPos;
// normal vector of the object
in vec3 Normal;
// Inputs the color from the Vertex Shader
in vec3 color;
// Inputs the texture coordinates from the Vertex Shader
in vec2 texCoord;



// Gets the Texture Unit from the main function
uniform sampler2D diffuse0;
uniform sampler2D specular0;

// gets Color of the light from main function
uniform vec4 lightColor;
// gets position of the light from main function
uniform vec3 lightPos;
// gets position of the camera from main function
uniform vec3 camPos;

vec4 pointLight()
{
    vec3 lightVec = lightPos-crntPos;
    float dist = length(lightVec);
    float a = 0.005f;
    float b = 0.01f;
    float intensity = 1/(a*dist*dist+b*dist+1.0f);

    //ambient lighting --> effect of other objects
    float ambient = 0.10f;

    // diffuse lighting
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightVec);
    float diffuse = max(abs(dot(normal,lightDirection)),0.0f);

    //specular lighting --> reflection of light from the object
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos-crntPos);
    vec3 reflectionDirection = reflect(-lightDirection,normal);
    float specAmount = pow(max(dot(viewDirection,reflectionDirection),0.0f),16);
    float specular = specAmount * specularLight;

    if (texture(diffuse0, texCoord).a < 0.2)
    discard;
    return (texture(diffuse0, texCoord)* (diffuse*intensity + ambient)+ texture(specular0, texCoord).r * specular*intensity)*lightColor;
}

vec4 directLight()
{
    // ambient lighting
    float ambient = 0.20f;

    // diffuse lighting
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(vec3(1.0f, 0.0f, 0.0f));
    float diffuse = max(abs(dot(normal, lightDirection)), 0.0f); // absolute helps with grass shading

    // specular lighting
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos - crntPos);
    vec3 reflectionDirection = reflect(-lightDirection, normal);
    float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
    float specular = specAmount * specularLight;

    // discards all fragments with alpha less than 0.1
    if (texture(diffuse0, texCoord).a < 0.1)
    discard;

    return (texture(diffuse0, texCoord) * (diffuse + ambient) + texture(specular0, texCoord).r * specular) * lightColor;
}

vec4 spotLight()
{
    float innerCone = 0.95f;
    float outerCone = 0.90f;

    float ambient = 0.10f;

    // diffuse lighting
    vec3 normal = normalize(Normal);
    vec3 lightDirection = normalize(lightPos-crntPos);
    float diffuse = max(dot(normal,lightDirection),0.0f);

    //specular lighting --> reflection of light from the object
    float specularLight = 0.50f;
    vec3 viewDirection = normalize(camPos-crntPos);
    vec3 reflectionDirection = reflect(-lightDirection,normal);
    float specAmount = pow(max(dot(viewDirection,reflectionDirection),0.0f),16);
    float specular = specAmount * specularLight;

    float angle = dot(vec3(0.0f,-1.0f,0.0f),-lightDirection);
    float intensity = clamp((angle-outerCone)/(innerCone-outerCone),0.0f,1.0f);

    return (texture(diffuse0, texCoord)* (diffuse*intensity + ambient)+ texture(specular0, texCoord).r * specular*intensity)*lightColor;

}

float near = 0.1f;
float far = 100.0f;

float linearizedDepth(float depth)
{
    return (2.0f*near*far)/(far+near-(depth*2.0f-1.0f)*(far-near));
}
float logisticDepth(float depth, float steepness,float offset)
{
    float zVal = linearizedDepth(depth);
    return(1 / (1 + exp(-steepness*(zVal-offset))));
}

void main()
{
    // outputs final color

    FragColor = pointLight();
}