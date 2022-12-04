#version 330 core
out vec4 FragColor;

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};


uniform sampler2D texture_diffuse1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_specular1;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform float shininess;
uniform Light light;

void main()
{    
    vec3 ambient = light.ambient * texture(texture_diffuse1, TexCoords).rgb;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * texture(texture_diffuse1, TexCoords).rgb;  
    


    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    //vec3 mid_dir = normalize(viewDir+lightDir);
    vec3 reflectDir = reflect(-lightDir, norm);  
    //float spec = pow(max(dot(viewDir, reflectDir), 0.0), shininess);
    float spec = max(dot(reflectDir, viewDir), 0.0); 
    float single = texture(texture_specular1, TexCoords).r; 
    vec3 specular_color = vec3(single, single, single);
    vec3 specular = light.specular * spec * specular_color;  
        
    vec3 result = ambient+diffuse+specular;
    FragColor = vec4(0,0,0, 1.0);
}