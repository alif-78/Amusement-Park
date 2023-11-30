#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "bed.h"
#include "shader.h"
#include "camera.h"
#include "basic_camera.h"
#include "pointLight.h"
#include "directionalLight.h"
#include "SpotLight.h"
#include "walls.h"
#include "bench.h"
#include "swing.h"
#include "stand.h"
#include "cube.h"
#include "stb_image.h"
#include "cylinderStand.h"
#include <iostream>
#include "sphere.h"
#include "drawcube.h"
struct Point {
    float x;
    float y;
    float z;
};
std::vector<float>cXALL;
std::vector<float>cZALL;
float cRALL = 6.5;

int kp1 = 0;
int kp3 = 0;
int kp4 = 0;
int kp5 = 0;
int flagDOLNA = 0;


std::vector<float>cX2;
std::vector<float>cZ2;
float cR2 = 6;
float dseatheta = 0.0;
int flagsd = -2;
int flagsd1 = -2;
float dseatheta100 = 0.0;
//float dyy = 0.0;
//float dxxx = 0.0;
float dxxtamim = 0.0;
float dyytamim = 0.0;


float rtheta = 0.0;
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void railstation(unsigned int& bezierVAO, unsigned int& bezierCylinderVAO, unsigned int& cubeVAO, Shader& lightingShader, float x, float y, float z, float r, float g, float bl);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void nagordola(unsigned int&bezierVAO,unsigned int &cubeVAO, Shader& lightingShader, Sphere &sphere, vector<float> &cx,vector<float>&cz,
    float tx1, float ty1,float tz1, float sx1, float sy1, float sz1
    );
void tree(unsigned int& bezierTree, unsigned int& bezierMatha, unsigned int& bezierCylinder, unsigned int& cubeVAO, Shader &lightingShader, Sphere& sphere, float tx1, float ty1, float tz1, float sx1, float sy1, float sz1);
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax);
void processInput(GLFWwindow* window);
void rocketDriver(unsigned int& bezierCylinderVAO, unsigned int&bezierCyCurve, unsigned int& bezierMatha, unsigned int& cubeVAO, Shader& lightingShader, vector<float>& 
    , vector<float>& cz1,float txr,float tyr,float tzr,float ctz);//jinat1
void dolna(unsigned int& bezierCylinder, unsigned int& bezierDolna, unsigned int& bezierMatha, unsigned int& cubeVAO, Shader& lightingShader,
    vector<float>& cx1, vector<float>& cz1,
    float cmnx, float cmny, float cmnz
);
void sleeper(unsigned int& bezierVAO, unsigned int& cubeVAO, Shader& lightingShader, Sphere& sphere, vector<float>& cx, vector<float>& cz,
    float tx1, float ty1, float tz1, float sx1, float sy1, float sz1);
void singleDolna(unsigned int& cubeVAO, Cube& cube1, Shader& lightingShader, Shader& ligthingwithtexture, float tx, float ty, float tz);

void bera(unsigned int& bezierMatha, unsigned int& cubeVAO, Cube& cube, Shader& lightingShader, Shader& ligthingwithtexture, float tx, float ty, float tz);
long long nCr(int n, int r);
void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L);
void lamp(unsigned int& cubeVAO, Shader& lightingShader, float tx1, float ty1, float tz1, float sx1, float sy1, float sz1);
unsigned int hollowBezier(GLfloat ctrlpoints[], int L);
void tamim(unsigned int& bezierCylinderVAO, unsigned int& bezierCyCurve, unsigned int& bezierMatha, unsigned int& cubeVAO, Shader& lightingShader, Shader& lightingShaderWithTexture, Cube& color,
    vector<float>& cx1, vector<float>& cz1,
    float txr, float tyr, float tzr, float ctz, glm::mat4 altogether
);
void coffeeshop(unsigned int& cubeVAO, Cube& coffee, Cube& coffee1, Cube& coffee2, Shader& lightingShader, Shader& lightingShaderWithTexture, float txC, float tyC, float tzC);
glm::mat4 transform(float tr_x, float tr_y, float tr_z, float rot_x, float rot_y, float rot_z, float scal_x, float scal_y, float scal_z) {
    // Modelling Transformation
    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
    translateMatrix = glm::translate(identityMatrix, glm::vec3(tr_x, tr_y, tr_z));
    rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rot_x), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rot_y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rot_z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(identityMatrix, glm::vec3(scal_x, scal_y, scal_z));
    model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
    return model;
}
// settings
const unsigned int SCR_WIDTH = 1500;
const unsigned int SCR_HEIGHT = 800;

// modelling transform
float rotateAngle_X = 0.0;
float rotateAngle_Y = 0.0;
float rotateAngle_Z = 0.0;
float rotateAxis_X = 0.0;
float rotateAxis_Y = 0.0;
float rotateAxis_Z = 1.0;
float translate_X = 0.0;
float translate_Y = 0.0;
float translate_Z = 0.0;
float scale_X = 1.0;
float scale_Y = 1.0;
float scale_Z = 1.0;
float dx = 0.000;
int  flag = 4;
int nightflag = 1;
int flagSD = 4;
float dy = 0.0000;
float dxx = 0.0000;
float dtheta = 0.0;
float dthetaY = 0.0;
int flagSeeSaw = 1;
float dtheta12 = 0.0;
int flagR = 0;
float dyL = 0.0;
int flagNagordola = 0;
int Ni = 0;
int tiTest = 0;
int flagTest = 1;
int flagRocket = 0;
float dthetaX = 0.0;
int rocketI = 0;
int rt = 899;
int rti = 1799;
int rtii = 2699;
int rtiii = 3599;
int di = 599;
int dii = 1199;
int diii = 1799;
int diiv = 2399;
int dv = 2999;
int dvi = 3599;

//float txr = 0.0;
//float tyr = 0.0;
//float tzr = 0.0;

//control points
vector<float> cntrlPoints
{
    -0.1200, 1.9950, 5.1000,
    -0.3150, 1.8950, 5.1000,
    -0.4600, 1.7800, 5.1000,
    -0.6000, 1.6600, 5.1000,
    -0.7050, 1.5650, 5.1000,
    -0.8500, 1.4550, 5.1000,
    -0.9550, 1.3800, 5.1000,
    -1.0550, 1.2850, 5.1000,
};
vector<float> cntrlForDolna
{
    -0.6700, 1.7400, 5.1000,
    -0.6650, 1.5000, 5.1000,
    -0.5750, 1.2950, 5.1000,
    -0.4150, 1.1700, 5.1000,
    -0.2350, 1.0550, 5.1000,
};
vector<float> cntrlPointsCylinder
{
-0.4500, 1.7950, 5.1000,
-0.4550, 1.4950, 5.1000,
-0.4550, 1.0000, 5.1000,
};
vector<float> cntrlPointsForNagordola
{
    -0.5900, 1.7200, 5.1000,
    -0.5100, 1.3700, 5.1000,
    -0.4050, 1.2150, 5.1000,
    -0.2850, 1.1150, 5.1000,
    -0.2300, 1.0450, 5.1000,
    -0.3050, 0.9650, 5.1000,
    -0.3850, 0.9250, 5.1000,
};
vector<float> cntrlPointstree
{
    
    
-0.2500, 1.8350, 5.1000,
-0.4700, 1.6950, 5.1000,
-0.7050, 1.4400, 5.1000,
-0.6600, 1.2550, 5.1000,
-0.4150, 1.2000, 5.1000,

    
};
vector<float> cntrlCyCurve
{
-0.3100, 1.5250, 5.1000,
-0.4400, 1.2950, 5.1000,
-0.5450, 1.1200, 5.1000,
-0.6350, 0.9500, 5.1000,
};

vector<float> cntrlmatha
{

    -0.0200, 1.9100, 5.1000,
    -0.1850, 1.7550, 5.1000,
    -0.3300, 1.5600, 5.1000,

};



int tiii = 3599;
int tii = 2699;
int ti = 1799;
int t = 899;
float irt = 0.0;
float irtz = 0.0;

vector <float> coordinates;
vector <float> normals;
vector <int> indices;
vector <float> vertices;
class point
{
public:
    point()
    {
        x = 0;
        y = 0;
    }
    int x;
    int y;
} clkpt[2];
int mouseButtonFlag = 0;
FILE* fp;
const double pi = 3.14159265389;
const int nt = 40;
const int ntheta = 20;
bool showControlPoints = true;
bool loadBezierCurvePoints = false;
bool showHollowBezier = false;
bool lineMode = false;
unsigned int bezierVAO;
unsigned int bezierCylinderVAO;
unsigned int bezierForNagordola;
unsigned int bezierTree;
unsigned int bezierCyCurve;
unsigned int bezierMatha;
unsigned int bezierDolna;

// camera
Camera camera(glm::vec3(-10.5f+25, 16.15f, -6.6 + 0.25f + 60.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

float eyeX = 0.0, eyeY = 1.0, eyeZ = 3.0;
float lookAtX = 0.0, lookAtY = 0.0, lookAtZ = 0.0;
glm::vec3 V = glm::vec3(0.0f, 1.0f, 0.0f);


// positions of the point lights

glm::vec3 pointLightPositions[] = {
    glm::vec3(72.0f,  24.15f,  -6.6 + 0.25f + 55.0f),
    glm::vec3(-10.5f,  24.15f,   -32.5f),
    glm::vec3(72.0f, 24.15f, -32.5f),
    glm::vec3(-10.5f,  24.15f,   -6.6 + 0.25f + 55.0f),
    
};

PointLight pointlight1(

    pointLightPositions[0].x, pointLightPositions[0].y, pointLightPositions[0].z,  // position
        // ambient
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.014f,  //k_l
    0.0007, //k_q
    1       // light number
);

PointLight pointlight3(

    pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.014f,  //k_l
    0.0007, //k_q
    2       // light number
);



//PointLight pointlight3(
//
//    pointLightPositions[1].x, pointLightPositions[1].y, pointLightPositions[1].z,  // position
//    0.5f, 0.5f, 0.5f,     // ambient
//    0.0f, 1.0f, 1.0f,     // diffuse
//    1.0f, 1.0f, 1.0f,        // specular
//    1.0f,   //k_c
//    0.35f,  //k_l
//    0.44f, //k_q
//    2       // light number
//);

PointLight pointlight4(

    pointLightPositions[2].x, pointLightPositions[2].y, pointLightPositions[2].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.014f,  //k_l
    0.0007, //k_q
    3       // light number
);
PointLight pointlight5(

    pointLightPositions[3].x, pointLightPositions[3].y, pointLightPositions[3].z,  // position
    0.05f, 0.05f, 0.05f,     // ambient
    0.8f, 0.8f, 0.8f,     // diffuse
    1.0f, 1.0f, 1.0f,        // specular
    1.0f,   //k_c
    0.014f,  //k_l
    0.0007, //k_q
    4       // light number
);



DirLight dirLight(
        -0.2f, -1.0f, -0.3f,
        0.05f, 0.05f, 0.05f,
        .5f, 0.5f, 0.5f,     // diffuse
        0.5f, 0.5f, 0.5f
);


SpotLight spotLight(
    -3.50f, 4.0f, -2.0f,
    0.6f, -1.0f, 0.5f,
    0.5f, 0.0f, 0.5f,
    1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,
    0.09f,
    0.032f,
    12.5f,
    15.0f
);



// light settings
bool PointToggle1 = true;
bool PointToggle3 = true;
bool PointToggle4 = true;
bool ambientToggle = true;
bool diffuseToggle = true;
bool specularToggle = true;


// timing
float deltaTime = 1.5f;    // time between current frame and last frame
float lastFrame = 0.0f;


int main()
{
    cout << "Train: B" << endl;
    cout << "SkyDrop: N" << endl;
    cout << "RockerDriver: Z & 1" << endl;
    cout << "Dolna: H & J" << endl;
    cout << "Nagordola: F & G" << endl;
    cout << "Electric Car: M" << endl;
    // glfw: initialize and configure
    // ------------------------------
    int ti = 0;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "CSE 4208: Computer Graphics Laboratory", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader lightingShader("vertexShaderForPhongShading.vs", "fragmentShaderForPhongShading.fs");
    //Shader lightingShader("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");
    
    //Shader lightingShader("vertexShaderForGouraudShading.vs", "fragmentShaderForGouraudShading.fs");
    Shader ourShader("vertexShader.vs", "fragmentShader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    

    float cube_vertices[] = {
        // positions      // normals
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        1.0f, 0.0f, 0.0f, 0.0f, 0.0f, -1.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f, //back side of cube, surface normal on -z 
        0.0f, 1.0f, 0.0f, 0.0f, 0.0f, -1.0f,

        1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, //
        1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f,

        0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f,

        0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f
    };
    unsigned int cube_indices[] = {
        0, 3, 2,
        2, 1, 0,

        4, 5, 7,
        7, 6, 4,

        8, 9, 10,
        10, 11, 8,

        12, 13, 14,
        14, 15, 12,

        16, 17, 18,
        18, 19, 16,

        20, 21, 22,
        22, 23, 20
    };

    unsigned int cubeVAO, cubeVBO, cubeEBO; 
    glGenVertexArrays(1, &cubeVAO);
    glGenBuffers(1, &cubeVBO);
    glGenBuffers(1, &cubeEBO);

    glBindVertexArray(cubeVAO); 

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertices), cube_vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cube_indices), cube_indices, GL_STATIC_DRAW);


    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // vertex normal attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)12);
    glEnableVertexAttribArray(1);

    // second, configure the light's VAO (VBO stays the same; the vertices are the same for the light object which is also a 3D cube)
    unsigned int lightCubeVAO;
    glGenVertexArrays(1, &lightCubeVAO);
    glBindVertexArray(lightCubeVAO);

    glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    // note that we update the lamp's position attribute's stride to reflect the updated buffer data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //cylinder sd points
    std::vector<Point> cylinder;
    //cylinder.push_back({ 0, 0, -8 });
    float radius1 = 2.0;
    float radius = 1.0;
    for (float theta = 0; theta <= 360; theta += 1) {
        float x = radius * glm::cos(glm::radians(theta));
        float y = radius * glm::sin(glm::radians(theta));

        float x1 = radius1 * glm::cos(glm::radians(theta));
        float y1 = radius1 * glm::sin(glm::radians(theta));

        cylinder.push_back({ x, y, 0.0f });
        cylinder.push_back({ x1, y1, -2.0f }); // normal cylinder
        //cylinder.push_back({ x * .5f, y * .5f, -8.0f }); // cylinder with different circle radius
    }

    unsigned int CVBO, CVAO;
    glGenVertexArrays(1, &CVAO);
    glGenBuffers(1, &CVBO);

    glBindVertexArray(CVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct Point) * cylinder.size(), cylinder.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Point), (void*)0);
    glEnableVertexAttribArray(0);
    //end of sd cylinder point

    //CYLINDER CIRCLE POINTS START
    std::vector<Point> cylindercircle;
    cylindercircle.push_back({ 0, 0, -8 });
    float radiusC = 6.0;
    //float radius = 1.0;
    for (float theta = 0; theta <= 360; theta += 1) {
        float x = radiusC * glm::cos(glm::radians(theta));
        float y = radiusC * glm::sin(glm::radians(theta));

        //float x1 = radius1 * glm::cos(glm::radians(theta));
        //float y1 = radius1 * glm::sin(glm::radians(theta));

        cylindercircle.push_back({ x, y, -8.0f });
        //cylinder.push_back({ x1, y1, -2.0f }); // normal cylinder
        //cylinder.push_back({ x * .5f, y * .5f, -8.0f }); // cylinder with different circle radius
    }

    unsigned int CcVBO, CcVAO;
    glGenVertexArrays(1, &CcVAO);
    glGenBuffers(1, &CcVBO);

    glBindVertexArray(CcVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CcVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct Point) * cylindercircle.size(), cylindercircle.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Point), (void*)0);
    glEnableVertexAttribArray(0);
    //end of sd cylinderCIRCLE point







    // cylinder maku points start
    std::vector<Point> cylinderMaku;
    cylinderMaku.push_back({ 0, 0, -15 });
    float radiusM = 6.0;
    //float radius = 1.0;
    for (float theta = 0; theta <= 360; theta += 1) {
        float x = radiusM * glm::cos(glm::radians(theta));
        float y = radiusM * glm::sin(glm::radians(theta));

        //float x1 = radius1 * glm::cos(glm::radians(theta));
        //float y1 = radius1 * glm::sin(glm::radians(theta));

        cylinderMaku.push_back({ x, y, -8.0f });
        //cylinder.push_back({ x1, y1, -2.0f }); // normal cylinder
        //cylinder.push_back({ x * .5f, y * .5f, -8.0f }); // cylinder with different circle radius
    }

    unsigned int CMVBO, CMVAO;
    glGenVertexArrays(1, &CMVAO);
    glGenBuffers(1, &CMVBO);

    glBindVertexArray(CMVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CMVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct Point) * cylinderMaku.size(), cylinderMaku.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Point), (void*)0);
    glEnableVertexAttribArray(0);
    //end of sd cylinderMaku point


    //cylinder for rider shade
    std::vector<Point> cylinderShade;
    //cylinder.push_back({ 0, 0, -8 });
    float radiusSh = 3.0;
    for (float theta = 0; theta <= 360; theta += 1) {
        float x = radiusSh * glm::cos(glm::radians(theta));
        float y = radiusSh * glm::sin(glm::radians(theta));

        cylinderShade.push_back({ x, y, 0.0f });
        cylinderShade.push_back({ x, y, -2.0f }); // normal cylinder
        //cylinder.push_back({ x * .5f, y * .5f, -8.0f }); // cylinder with different circle radius
    }

    unsigned int CSVBO, CSVAO;
    glGenVertexArrays(1, &CSVAO);
    glGenBuffers(1, &CSVBO);

    glBindVertexArray(CSVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CSVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(struct Point) * cylinderShade.size(), cylinderShade.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(struct Point), (void*)0);
    glEnableVertexAttribArray(0);


    bezierVAO = hollowBezier(cntrlPoints.data(), ((unsigned int)cntrlPoints.size() / 3) - 1);
    coordinates.clear();
    normals.clear();
    indices.clear();
    vertices.clear();

    bezierCylinderVAO = hollowBezier(cntrlPointsCylinder.data(), ((unsigned int)cntrlPointsCylinder.size() / 3) - 1);
    //cout << bezierCylinderVAO << endl;
    coordinates.clear();
    normals.clear();
    indices.clear();
    vertices.clear();

    bezierForNagordola = hollowBezier(cntrlPointsForNagordola.data(), ((unsigned int)cntrlPointsForNagordola.size() / 3) - 1);
    coordinates.clear();
    normals.clear();
    indices.clear();
    vertices.clear();

    bezierTree = hollowBezier(cntrlPointstree.data(), ((unsigned int)cntrlPointstree.size() / 3) - 1);
    coordinates.clear();
    normals.clear();
    indices.clear();
    vertices.clear();

    bezierCyCurve = hollowBezier(cntrlCyCurve.data(), ((unsigned int)cntrlCyCurve.size() / 3) - 1);
    coordinates.clear();
    normals.clear();
    indices.clear();
    vertices.clear();

    bezierMatha = hollowBezier(cntrlmatha.data(), ((unsigned int)cntrlmatha.size() / 3) - 1);
    coordinates.clear();
    normals.clear();
    indices.clear();
    vertices.clear();
    
    bezierDolna = hollowBezier(cntrlForDolna.data(), ((unsigned int)cntrlForDolna.size() / 3) - 1);



    //end of cylinderShade point

    //points for move an object in circle
    std::vector<float>cX;
    std::vector<float>cZ;
    float cR = 6;
    for (float itheta = 0;itheta <= 360;itheta = itheta + 0.1)
    {
        float x = cR * glm::cos(glm::radians(itheta));
        float z = cR * glm::sin(glm::radians(itheta));
        cX.push_back(x);
        cZ.push_back(z);
    }
    for (float itheta = 0;itheta <= 360;itheta = itheta + 0.1)
    {
        float x = cRALL * glm::cos(glm::radians(itheta));
        float z = cRALL * glm::sin(glm::radians(itheta));
        cXALL.push_back(x);
        cZALL.push_back(z);
    }
    std::cout << cX.size() << endl;
    std::cout << cZ.size() << endl;
    std::vector<float>cXt;
    std::vector<float>cZt;
    float cR1 = 6;
    for (float itheta = 1;itheta <= 360;itheta = itheta + 1.0)
    {
        float x = cR1 * glm::cos(glm::radians(itheta));
        float z = cR1 * glm::sin(glm::radians(itheta));
        cXt.push_back(x);
        cZt.push_back(z);
    }
    cout << "cXt = " << cXt.size() << endl;
    //cX2.push_back(0.0);
    //cZ2.push_back(0.0);
    /*for (float itheta = 0;itheta <= 360;itheta = itheta + 0.5)
    {
        float x = cR2 * glm::cos(glm::radians(itheta));
        float z = cR2 * glm::sin(glm::radians(itheta));
        cX2.push_back(x);
        cZ2.push_back(z);
    }
    cout << cX2.size() << endl;*/


    
    
    
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    //ourShader.use();
    //lightingShader.use();

    // render loop
    // -----------

    // abrar er vdo dekhe ana code
    Shader lightingShaderWithTexture("vertexShaderForPhongShadingWithTexture.vs", "fragmentShaderForPhongShadingWithTexture.fs");
    //Shader ourShader("vertexShader.vs", "fragmentShader.fs");
    string diffuseMapPath = "./container2.jpg";
    string specularMapPath = "./container2.jpg";
    string diffuseMapRoad = "./road.jpg";
    string specularMapRoad = "./road.jpg";
    string diffuseMapSky = "./sky.jpg";
    string specularMapSky = "./sky.jpg";
    string diffuseMapBrick = "./colr.jpg";
    string specularMapBrick = "./colr.jpg";
    string diffuseMapColor = "./color.jpg";
    string specularMapColor = "./color.jpg";
    string diffuseMapSofa = "./k1.jpg";
    string specularMapSofa = "./k1.jpg";
    string diffuseMapWater =  "./water.jpg";
    string specularMapWater = "./water.jpg";
    string diffuseMapCoffee = "./cffee1.jpg";
    string specularMapCoffee = "./cffee1.jpg";

    string diffuseMapCoffeeNes = "./nes.jpg";
    string specularMapCoffeeNes = "./nes.jpg";

    string diffuseMapWell = "./wel.png";
    string specularMapWell = "./wel.png";

    string diffuseMapWood = "./wood.jpg";
    string specularMapWood = "./wood.jpg";

    unsigned int diffMap = loadTexture(diffuseMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap = loadTexture(specularMapPath.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap1 = loadTexture(diffuseMapRoad.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap1 = loadTexture(specularMapRoad.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap2 = loadTexture(diffuseMapSky.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap2 = loadTexture(specularMapSky.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap3 = loadTexture(diffuseMapBrick.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap3 = loadTexture(specularMapBrick.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap4 = loadTexture(diffuseMapSofa.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap4 = loadTexture(specularMapSofa.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap5 = loadTexture(diffuseMapColor.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap5 = loadTexture(specularMapColor.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap6 = loadTexture(diffuseMapWater.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap6 = loadTexture(specularMapWater.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap7 = loadTexture(diffuseMapCoffee.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap7 = loadTexture(specularMapCoffee.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap8 = loadTexture(diffuseMapCoffee.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap8 = loadTexture(specularMapCoffee.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap9 = loadTexture(diffuseMapCoffeeNes.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap9 = loadTexture(specularMapCoffeeNes.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int diffMap10 = loadTexture(diffuseMapWell.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap10 = loadTexture(specularMapWell.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    unsigned int diffMap11 = loadTexture(diffuseMapWood.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    unsigned int specMap11 = loadTexture(specularMapWood.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);

    Cube road = Cube(diffMap1, specMap1, 32.0f, 0.0f, 0.0f, 2.0f, 2.0f);
    Cube water = Cube(diffMap6, specMap6, 32.0f, 0.0f, 0.0f, 100.0f, 100.0f);
    Cube brick = Cube(diffMap3, specMap3, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube sky = Cube(diffMap2, specMap2, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube sofa = Cube(diffMap4, specMap4, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube color = Cube(diffMap5, specMap5, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube coffee = Cube(diffMap7, specMap7, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube coffeeT = Cube(diffMap8, specMap8, 32.0f, 0.0f, 0.0f, 3.0f, 1.0f);
    Cube coffeT2 = Cube(diffMap9, specMap9, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
    Cube well = Cube(diffMap10, specMap10, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);

    Cube wood = Cube(diffMap11, specMap11, 32.0f, 0.0f, 0.0f, 1.0f, 1.0f);
 
    //std::cout << diffMap << ' ' << specMap << std::endl;
    Cube cube = Cube(diffMap, specMap, 32.0f, 0.0f, 0.0f, 20.0f, 20.0f);
    Cube cube1 = Cube();
    Sphere sphere = Sphere(0.8);
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.5294f, 0.8078f, 0.9804f, 0.08f);
        if (nightflag == 2)
        {
            glClearColor(0.0f,0.0f,0.0f, 0.08f);
            

        }
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // be sure to activate shader when setting uniforms/drawing objects
        lightingShader.use();
        lightingShader.setVec3("viewPos", camera.Position);
        // point light 1
        pointlight1.setUpPointLight(lightingShader);
        // point light 2
        //pointlight2.setUpPointLight(lightingShader);
        // point light 3
        pointlight3.setUpPointLight(lightingShader);
        // point light 4
        pointlight4.setUpPointLight(lightingShader);
        pointlight5.setUpPointLight(lightingShader);
        dirLight.setUpDirLight(lightingShader);
        spotLight.setUpSpotLight(lightingShader);
        lightingShader.use();
        //lightstand
        /*glm::vec3(72.0f, 24.15f, -6.6 + 0.25f + 55.0f),
            glm::vec3(-10.5f, 24.15f, -32.5f),
            glm::vec3(72.0f, 24.15f, -32.5f),
            glm::vec3(-10.5f, 24.15f, -6.6 + 0.25f + 55.0f),*/
        //for (unsigned int i = 2; i < 4; i++)
        //{
        //    glm::mat4 model = glm::mat4(1.0f);
        //    model = glm::translate(model, pointLightPositions[i]);
        //    model = glm::scale(model, glm::vec3(0.50f, -40.0f, 0.9f)); // Make it a smaller cube
        //    lightingShader.setMat4("model", model);
        //    lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        //    drawCube(cubeVAO, lightingShader, model, 0.0f, 0.0f, 0.0f);
        //}
        glm::mat4 modelight = glm::mat4(1.0f);
        modelight = glm::translate(modelight, glm::vec3(72.5f+0.5, 24.15f, -6.6 + 0.25f + 55.0f+0.5+0.5));
        modelight = glm::scale(modelight, glm::vec3(0.50f, -40.0f, 0.5f)); // Make it a smaller cube
        lightingShader.setMat4("model", modelight);
        lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, modelight, 0.0f, 0.0f, 0.0f);

        modelight = glm::mat4(1.0f);
        modelight = glm::translate(modelight, glm::vec3(-10.0f+0.5-10, 25.15f, -33.5f+0.5+0.5));
        modelight = glm::scale(modelight, glm::vec3(0.50f, -40.0f, 0.5f)); // Make it a smaller cube
        lightingShader.setMat4("model", modelight);
        lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, modelight, 0.0f, 0.0f, 0.0f);

        modelight = glm::mat4(1.0f);
        modelight = glm::translate(modelight, glm::vec3(-10.0f + 0.5 - 10, 25.15f, -33.5f + 0.5 + 0.5));
        modelight = glm::scale(modelight, glm::vec3(10.50f, -0.50f, 0.5f)); // Make it a smaller cube
        lightingShader.setMat4("model", modelight);
        lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, modelight, 0.0f, 0.0f, 0.0f);

        modelight = glm::mat4(1.0f);
        modelight = glm::translate(modelight, glm::vec3(72.5f+10.5, 25.15f, -33.5f+0.5+0.5));
        modelight = glm::scale(modelight, glm::vec3(0.50f, -40.0f, 0.5f)); // Make it a smaller cube
        lightingShader.setMat4("model", modelight);
        lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, modelight, 0.0f, 0.0f, 0.0f);

        modelight = glm::mat4(1.0f);
        modelight = glm::translate(modelight, glm::vec3(72.5f + 10.5, 25.15f, -33.5f + 0.5 + 0.5));
        modelight = glm::scale(modelight, glm::vec3(-10.50f, -0.50f, 0.5f)); // Make it a smaller cube
        lightingShader.setMat4("model", modelight);
        lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, modelight, 0.0f, 0.0f, 0.0f);

        modelight = glm::mat4(1.0f);
        modelight = glm::translate(modelight, glm::vec3(-10.0f+0.5, 24.15f, -6.6 + 0.25f + 55.0f+0.5+0.5));
        modelight = glm::scale(modelight, glm::vec3(0.50f, -40.0f, 0.5f)); // Make it a smaller cube
        lightingShader.setMat4("model", modelight);
        lightingShader.setVec3("color", glm::vec3(0.0f, 0.0f, 0.0f));
        drawCube(cubeVAO, lightingShader, modelight, 0.0f, 0.0f, 0.0f);
        




        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        //glm::mat4 projection = glm::ortho(-2.0f, +2.0f, -1.5f, +1.5f, 0.1f, 100.0f);
        lightingShader.setMat4("projection", projection);


        // Modelling Transformation
        glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, model;
        translateMatrix = glm::translate(identityMatrix, glm::vec3(translate_X, translate_Y, translate_Z));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(scale_X, scale_Y, scale_Z));
        model = translateMatrix * rotateXMatrix * rotateYMatrix * rotateZMatrix * scaleMatrix;
        lightingShader.setMat4("model", model);

        //railstation(bezierVAO, bezierCylinderVAO, cubeVAO,lightingShader, 78.0, -1.9 + 5, -20.5, 0.0, 0.0, 0.0);
        nagordola(bezierForNagordola,cubeVAO, lightingShader,sphere, cX, cZ, 15+5,1.4,35,0-1,0-1,0-1 );
        sleeper(bezierForNagordola, cubeVAO, lightingShader, sphere, cX, cZ, 15 + 5, 1.4, 20, 0 - 1, 0 - 1, 0 - 1);
        //tree(bezierTree, bezierMatha, bezierCylinderVAO, cubeVAO, lightingShader, sphere, 0, 0, 35, -3, -3, -3);
        tree(bezierTree,bezierMatha,bezierCylinderVAO,cubeVAO, lightingShader,sphere, -47+94, 0, 35, 0, 0, 0);
        int treeI = 0;
        int treeII;
        for (int i = 0;i < 6;i++)
        {
            tree(bezierTree, bezierMatha, bezierCylinderVAO, cubeVAO, lightingShader, sphere, -48, 0, 35+treeI, 0, 0, 0);
            treeI = treeI - 10;

        }
        treeII = treeI;
        treeI = 0;
        for (int i = 0;i < 9;i++)
        {
            tree(bezierTree, bezierMatha, bezierCylinderVAO, cubeVAO, lightingShader, sphere, -48+treeI, 0, 45 + treeII, 0, 0, 0);
            treeI = treeI + 10;

        }

        treeI = 0;
        for (int i = 0;i < 6;i++)
        {
            tree(bezierTree, bezierMatha, bezierCylinderVAO, cubeVAO, lightingShader, sphere, -47 + 94, 0, 35 + treeI, 0, 0, 0);
            treeI = treeI - 10;

        }
        rocketDriver(bezierCylinderVAO,bezierCyCurve,bezierMatha,cubeVAO, lightingShader,cX,cZ,-15.0,10,20.0,-8.0);
        dolna(bezierCylinderVAO, bezierDolna, bezierMatha, cubeVAO, lightingShader, cX, cZ, 4.0, 0.0, -24.0+22);//JINAT2
        //lamp(cubeVAO, lightingShader, 35.0, -3.50, -20.0, 0.0, 0.0, 0.0);
        


        
        


        // camera/view transformation
        float degree = 0;
        glm::mat4 view = camera.GetViewMatrix();
        float r = glm::length(camera.Position - glm::vec3(view[3]));
        ourShader.setMat4("view", view);
        ourShader.use();
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);
        //...................................skydriver Seat............................//
        glm::mat4 modelMaku1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0+dx, -2.5 + 1.0 + 3+11, (6.0 * 3)-10-40+3));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        scaleMatrix = glm::scale(model, glm::vec3(0.18f, 0.18f, 0.18f));
        modelMaku1 = translateMatrix * rotateXMatrix * scaleMatrix;
        ourShader.setMat4("model", modelMaku1);
        ourShader.setVec3("color", glm::vec3(0.925, 0.949, 0.929));
        ourShader.use();
        glBindVertexArray(CMVAO);
        glDrawArrays(GL_TRIANGLE_FAN, 0, cylinderMaku.size());

        
        glm::mat4 model1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0+dx, -2.5 + 3 + 11, (6.0 * 3)-10-40+3));
        //rotateXMatrix = glm::rotate(model, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        scaleMatrix = glm::scale(model, glm::vec3(0.8f, 1.2f, 0.8f));
        model1 = translateMatrix * rotateXMatrix * scaleMatrix;
        ourShader.setMat4("model", model1);
        ourShader.setVec3("color", glm::vec3(0.176, 0.153, 0.969));
        ourShader.use();
        glBindVertexArray(CVAO);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, cylinder.size());


        glm::mat4 modelMatrixForContainer2 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-3.0+dx, -2.5 + 3 +11, (5.970 * 3)-10-40+3));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 4.0f, 0.1f));
        modelMatrixForContainer2 = translateMatrix * scaleMatrix;
        ourShader.setMat4("model", modelMatrixForContainer2);
        //ourShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        //modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        cube.drawCube(ourShader, modelMatrixForContainer2, 0.0f, 0.0f, 0.0f);
        //sky driver object code ends here

        if (flag == 1)
        {
            dx = dx + 0.1;
            if (dx >=47)
            {
                flag = 2;
            }
        }
        if (flag == 2)
        {
            dx = dx - 0.1;
            if (dx <= -2)
            {
                flag = 4;
            }
            
        }
        //...................................skydriver Seat............................//
        




        


        


        




        //.............. we now draw as many light bulbs as we have point lights.................//
        glBindVertexArray(lightCubeVAO);
        ourShader.use();
        for (unsigned int i = 0; i < 4; i++)
        { 
            model = glm::mat4(1.0f);
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(2.0f,2.0f,0.9f)); // Make it a smaller cube
            ourShader.setMat4("model", model);
            ourShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
            
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            
            //model = glm::mat4(1.0f);
            //model = glm::translate(model, pointLightPositions[1]);
            //model = glm::scale(model, glm::vec3(0.3f)); // Make it a smaller cube
            //ourShader.setMat4("model", model);
            //ourShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
            //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

            //model = glm::mat4(1.0f);
            //model = glm::translate(model, pointLightPositions[2]);
            //model = glm::scale(model, glm::vec3(0.3f)); // Make it a smaller cube
            //ourShader.setMat4("model", model);
            //ourShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
            //glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            
        }
        //.............. we now draw as many light bulbs as we have point lights.................//
      
        //lighting texture for cube
        //lightingShader.use();
        //lightingShader.setVec3("viewPos", camera.Position);


        //// point light 1
        //pointlight1.setUpPointLight(lightingShader);
        //// point light 3
        //pointlight3.setUpPointLight(lightingShader);
        //// point light 4
        ////pointlight4.setUpPointLight(lightingShader);
        //dirLight.setUpDirLight(lightingShader);
        //spotLight.setUpSpotLight(lightingShader);
        //lightingShader.use();

        //.................................skyDrive stand................................//
        lightingShaderWithTexture.use();
        lightingShaderWithTexture.setVec3("viewPos", camera.Position);
        lightingShaderWithTexture.setMat4("projection", projection);
        lightingShaderWithTexture.setMat4("view", view);
        lightingShaderWithTexture.use();
        pointlight1.setUpPointLight(lightingShaderWithTexture);
        pointlight3.setUpPointLight(lightingShaderWithTexture);
        //pointlight4.setUpPointLight(lightingShaderWithTexture);
        pointlight5.setUpPointLight(lightingShaderWithTexture);

        //cube for skyDrive stand
        glm::mat4 modelMatrixForContainer1 = glm::mat4(1.0f);
        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00, -2.5, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 18.0f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        

        

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00, -2.5, 8.0 - 30 - 1));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 18.0f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.50, -2.5, 8.0 - 30 - 1.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 18.0f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.50, -2.5, 8.0 - 30 - 9.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 18.0f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        /*lightingShader.setMat4("model", modelMatrixForContainer1);
        drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);*/

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 9.85 + 4.5 + 40.00, -2.5, 8.0-30-10+4));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25f, 18.0f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        /*lightingShader.setMat4("model", modelMatrixForContainer1);
        drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);*/

        //siri
        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 11.50, -2.5 + 12.2, 8.0 - 30 - 10));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.0f, 1.50f, 0.70f));
        modelMatrixForContainer1 = translateMatrix * rotateZMatrix* scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 11.50, -2.5 + 12.2, 8.0 - 30 - 1-0.7+0.005));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(15.0f, 1.50f, 0.70f));
        modelMatrixForContainer1 = translateMatrix * rotateZMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);


        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.50, -2.5 + 18.2-0.25, 8.0 - 30 - 1 - 0.7+0.25));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(22.0f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * rotateZMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.50, -2.5 + 18.2 - 0.25, 8.0 - 30 - 1-9+0.5));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-60.f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(22.0f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * rotateZMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.60, -2.5 + 10.2, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.30f, 9.0f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.60+1.5-0.4, -2.5 + 8.2, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.30f, 9.0f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.60 + 1.5*2-0.75, -2.5 + 6.2, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.30f, 9.0f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.60 + 1.5 * 3-1, -2.5 + 4.2, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.30f, 9.0f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 12.60 + 1.5 * 4-1.25, -2.5 + 2.2, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.50f, 0.30f, 9.0f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        


        //tar
        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5+15-10+0.6, -2.5+18, 8.0-30-10+4));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(90.0f*3), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.1f, 49.6, 0.1f));
        modelMatrixForContainer1 = translateMatrix * rotateZMatrix *scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 0.0f, 0.0f, 0.0f);

        //base of stand
        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00, -2.5 + 12.2, 8.0 - 30 - 10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(7.0f, 1.50f, 9.0f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        //lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        //modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00+0.25, -2.5 + 15.2, 8.0 - 30 - 10+0.25));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.5f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00 + 0.25, -2.5 + 17.750, 8.0 - 30 - 10 + 0.25));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.5f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00 + 0.25, -2.5 + 15.2, 8.0 - 30 - 1 + 0.25));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.5f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00 + 0.25, -2.5 + 17.750, 8.0 - 30 - 1 + 0.25));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(6.5f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 6.00, -2.5 + 17.750, 8.0 - 30 - 1 + 0.25));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(9.0f, 0.250f, 0.25f));
        modelMatrixForContainer1 = translateMatrix * rotateYMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);
        //lightingShader.setMat4("model", modelMatrixForContainer1);
        ////lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 0.0f, 1.0f);




        //skyDriverStand ends here
        //.................................skyDrive stand................................//

        coffeeshop(cubeVAO, coffeeT,coffee,coffeT2, lightingShader, lightingShaderWithTexture, 0.0, 0.0, 0.0);











        //.....skyHI Rider stand..............//
        

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 66+5+8, -2.5, 10.0 - 30-10));
        //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(0.0), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-12.5f, 2.0f, 9.5f));
        modelMatrixForContainer1 = translateMatrix *  scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        //lightingShader.setVec3("color", glm::vec3(1.0f, 1.0f, 1.0f));
        //modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        drawCube(cubeVAO, lightingShader, modelMatrixForContainer1, 1.0f, 1.0f, 1.0f);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 63+5+8, -2.5+2, 10.0 - 30-10));
        //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(0.0), glm::vec3(0.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-6.5f, 30.0f, 2.5f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        brick.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);


        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64+5+8, -2.5 + 2+dy, 12.0 - 30-10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-8.5f, 04.0f, 0.60f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        color.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64+5+8, -2.5 + 2+1+dy, 12.8 - 30-10));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-8.5f, 0.50f, 1.60f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        color.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64 + 5 + 8+1.5, -2.5 + 2 + 1.5 + dy, 12.8 - 30 - 10+1.60));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-12.0f, 0.50f, 0.80f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64 + 5 + 8 + 1.5, -2.5 + 2 + 1.5 + dy, 12.8 - 30 - 10 + 1.60-1.60*2));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-12.0f, 0.50f, 0.80f));
        modelMatrixForContainer1 = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64 + 5 + 8 + 1.5, -2.5 + 2 + 1.5 + dy, 12.8 - 30 - 10 + 1.60 - 1.60 * 2));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-4.0f, 0.50f, 0.80f));
        modelMatrixForContainer1 = translateMatrix *rotateYMatrix* scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64 + 5 + 8 + 1.5-12.75, -2.5 + 2 + 1.5 + dy, 12.8 - 30 - 10 + 1.60 - 1.60 * 2));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-4.0f, 0.50f, 0.80f));
        modelMatrixForContainer1 = translateMatrix * rotateYMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 64+5+8, -2.5 + 2+dy, 12.0 - 30-10));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-2.5f, 02.0f, 0.60f));
        modelMatrixForContainer1 = translateMatrix * rotateYMatrix* scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        color.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        modelMatrixForContainer1 = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5 + 60+8, -2.5 + 2+dy, 12.0 - 30-10));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(-2.5f, 02.0f, 0.60f));
        modelMatrixForContainer1 = translateMatrix * rotateYMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelMatrixForContainer1);
        color.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer1);

        if (flagSD == 1)
        {
            dy = dy + 0.05;
            if (dy >= 30)
            {
                flagSD = 2;
            }
        }
        if (flagSD == 2)
        {
            dy = dy - 0.1;
            if (dy <= 0)
            {
                flagSD = 4;
            }

        }
       
    




       

  
       



        







        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        lightingShaderWithTexture.use();
        lightingShaderWithTexture.setVec3("viewPos", camera.Position);
        lightingShaderWithTexture.setMat4("projection", projection);
        lightingShaderWithTexture.setMat4("view", view);
        //2nd part of cube draw
        lightingShaderWithTexture.use();
        // point light 1
        pointlight1.setUpPointLight(lightingShaderWithTexture);
        // point light 3
        pointlight3.setUpPointLight(lightingShaderWithTexture);
        // point light 4
        pointlight4.setUpPointLight(lightingShaderWithTexture);

        // surface
        glm::mat4 modelMatrixForContainer = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5, -2.5, -32.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(90, .5, 50));
        modelMatrixForContainer = translateMatrix * scaleMatrix;
        //modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        cube.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer);


        // nodi surface
        modelMatrixForContainer = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-400.5, -2.6, -47.5));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1100, .5, 700));
        modelMatrixForContainer = translateMatrix * scaleMatrix;
        //modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        water.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer);


         //sky surface
        /*modelMatrixForContainer = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(-20.5, -2.6, -47.5));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f*3), glm::vec3(1.0f, 0.0f, 0.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(110, .5, 40));
        modelMatrixForContainer = translateMatrix * rotateXMatrix *scaleMatrix;
        sky.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer);*/

        //verticele surface y axis
        /*translateMatrix = glm::translate(identityMatrix, glm::vec3(-10.5, -2.5, -7.5));
        rotateXMatrix = glm::rotate(identityMatrix, glm::radians(90.0f*3), glm::vec3(1.0f, 0.0f, 1.0f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(60, .5, 40));
        modelMatrixForContainer = translateMatrix * rotateXMatrix * scaleMatrix;
        sky.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer);*/
     

        //road
        translateMatrix = glm::translate(identityMatrix, glm::vec3(12.5f+13, -1.9f, -32.5f));// y=-2.0 for surface
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(4, 0.001, 50));
        modelMatrixForContainer = translateMatrix * scaleMatrix;
        road.drawCubeWithTexture(lightingShaderWithTexture, modelMatrixForContainer);

       
        //beraInroadside
        int beraI = 0;
        int beraII;

        bera(bezierMatha, cubeVAO, sofa, lightingShader, lightingShaderWithTexture, -45, 0, 32+3);
        for (int i = 0;i < 5;i++)
        {
            bera(bezierMatha, cubeVAO, sofa, lightingShader, lightingShaderWithTexture, -45+beraI, 0, 32+3);
            beraI = beraI + 7;

        }
        glm :: mat4 modelLathi = glm::mat4(1.0f);
        identityMatrix = glm::mat4(1.0f);
        translateMatrix = glm::translate(modelLathi, glm::vec3(-45 + beraI-7 + 41.0f, - 2.0f, 32 - 11.5f+3));
        scaleMatrix = glm::scale(modelLathi, glm::vec3(0.3f, 12.5f, 0.3f));
        modelLathi = translateMatrix * scaleMatrix;
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

        modelLathi = glm::mat4(1.0f);
        identityMatrix = glm::mat4(1.0f);
        translateMatrix = glm::translate(modelLathi, glm::vec3(-45 + beraI - 7 + 41.0f, -2.0f+12.5, 32 - 11.5f+3));
        scaleMatrix = glm::scale(modelLathi, glm::vec3(7.3f, 4.5f, 0.3f));
        modelLathi = translateMatrix * scaleMatrix;
        well.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

        beraI = beraI + 1*7;
        modelLathi = glm::mat4(1.0f);
        identityMatrix = glm::mat4(1.0f);
        translateMatrix = glm::translate(modelLathi, glm::vec3(-45 + beraI -7 + 41.0f, -2.0f, 32 - 11.5f+3));
        scaleMatrix = glm::scale(modelLathi, glm::vec3(0.3f, 12.5f, 0.3f));
        modelLathi = translateMatrix * scaleMatrix;
        //lightingShader.setMat4("model", modelLathi);
        //drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
        sofa.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

        for (int i = 5;i < 14;i++)
        {
            bera(bezierMatha, cubeVAO, sofa, lightingShader, lightingShaderWithTexture, -45 + beraI, 0, 32+3);
            beraI = beraI + 7;

        }
        //singleDolna(cubeVAO, cube1, lightingShader, lightingShaderWithTexture, 0.0, -2.5, 0.0);

        glm::mat4 modeltamim = transform(4, 12, -1.8f, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
        //glm::mat4 modeltamim = transform(-10.5f + 29.5, -2.5f + 4.5f + 10.0, -7.8f - 6.0f, 0.0 + dthetaX, 0.0, 0.0, 1, 1, 1);
        //modeltamim = transform(0.0,0.0 ,0.0 ,0.0, 0.0+dthetaY, 0.0, 1, 1, 1) * modeltamim;
        //-10.5f + 29.5 + txr, -2.5f + 4.5f + tyr, -7.8f - 6.0f + tzr + ctz
        tamim(bezierCylinderVAO, bezierCyCurve, bezierMatha, cubeVAO, lightingShader,lightingShaderWithTexture,color, cX, cZ, -15.0, 10, 20.0, -8.0, modeltamim);
        





        //..........rail project start........//
        glm::mat4  modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(78.0f, -1.9f, -32.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 0.01, 50));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.0f, -1.9f, -32.5f));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.25, 0.01, 50));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        for (int i = 1;i < 14;i++)
        {
            modelTrainLine = glm::mat4(1.0f);
            translateMatrix = glm::translate(identityMatrix, glm::vec3(74.0f, -1.9f, -37.5f+4*i));
            scaleMatrix = glm::scale(identityMatrix, glm::vec3(5.0, 0.1, 1.0));
            modelTrainLine = translateMatrix * scaleMatrix;
            lightingShader.setMat4("model", modelTrainLine);
            drawCube(cubeVAO, lightingShader, modelTrainLine, 1.0f, 1.0f, 1.0f);

        }
        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.0f, -1.9f+0.3f, -32.5f+dxx));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.2, 3.0, 2.5));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 1.0f, 0.0f, 1.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(74.8f, -1.9f + 0.3f+3.1f, -32.5f + dxx));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 0.01, 2.5));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(74.8f, -1.9f + 0.3f + 2.7, -32.0f + dxx));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.4, 0.01, 2.0));
        modelTrainLine = translateMatrix * rotateZMatrix *scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        //...........................brownField........................//
        //glm::mat4 modelMatrixForContainerField = glm::mat4(1.0f);
        //translateMatrix = glm::translate(identityMatrix, glm::vec3(-400.5, -2.6, -47.5));
        //scaleMatrix = glm::scale(identityMatrix, glm::vec3(1100, .5, 700));
        //modelMatrixForContainerField = translateMatrix * scaleMatrix;
        //lightingShader.setMat4("model", modelMatrixForContainerField);
        ////modelMatrixForContainer = glm::translate(identityMatrix, glm::vec3(-0.45f, -0.4f, -2.8f));
        //drawCube(cubeVAO, lightingShader, modelMatrixForContainerField, 1.0f, 0.667f, 0.0f);
        //...........................brownField........................//



        //bogi

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.0f, -1.9f + 0.3f, -29.5f+dxx));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 3.0, 2.5));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 1.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(74.8f, -1.9f + 0.3f+3.1f, -29.5f + dxx));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 0.01, 2.5));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(74.8f, -1.9f + 0.3f + 2.7, -29.0f + dxx));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.4, 0.01, 2.0));
        modelTrainLine = translateMatrix * rotateZMatrix *scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        //bogi 2
        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.0f, -1.9f + 0.3f, -26.5f+dxx));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.2, 3.0, 2.5));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 1.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(74.8f, -1.9f + 0.3f+3.1, -26.5f + dxx));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 0.01, 2.5));
        modelTrainLine = translateMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(74.8f, -1.9f + 0.3f + 2.7, -26.0f + dxx));
        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0, 0.0, 1.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.01, 2.0));
        modelTrainLine = translateMatrix * rotateZMatrix *scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);




       
        
        glm::mat4  modelTrainLine1 = glm::mat4(1.0f); 
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.50f-dyL, -1.9f + 0.3f, -23.5f+dxx));
        //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(2.2, 1.5, 2.5));
        modelTrainLine1 = translateMatrix  *scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine1);
        drawCube(cubeVAO, lightingShader, modelTrainLine1, 1.0f, 0.0f, 0.0f);

        

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(76.1f-dyL, -1.9f + 0.4f, -23.5f+2.5f + dxx));
        //rotateYMatrix =  glm::rotate(identityMatrix, glm::radians(120.0f), glm::vec3(0.0, 1.0, 0.0));
        //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(-30.0f), glm::vec3(1.0, 0.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 1.0, 0.7));
        modelTrainLine = translateMatrix *scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        //drawCube(cubeVAO, lightingShader, modelTrainLine, 0.969f, 0.969f, 0.0f);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f,1.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.4f-dyL, -1.9f + 0.3f+1.4, -23.2f + dxx));

        rotateZMatrix = glm::rotate(identityMatrix, glm::radians(-90.0f), glm::vec3(0.0, 0.0, 1.0));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.0, 0.01, 2.0));
        modelTrainLine = translateMatrix * rotateYMatrix * rotateZMatrix *scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);


        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.60f-dyL, -1.9f + 0.3f+1.5+1.2, -23.1f + dxx));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(1.8, 0.1, 1.8));
        modelTrainLine = translateMatrix * rotateYMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 1.0f, 0.850f, 1.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(76.20f-dyL, -1.9f+1.9f, -21.6f+dxx));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.5, 0.5, 0.5));
        modelTrainLine = translateMatrix * rotateYMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.969f, 0.969f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.70f-dyL, -1.9f + 1.7f, -21.6f + dxx));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.07, 1.3, 0.07));
        modelTrainLine = translateMatrix * rotateYMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.50f+1.8f-dyL, -1.9f + 1.7f, -21.6f + dxx));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.07, 1.3, 0.07));
        modelTrainLine = translateMatrix * rotateYMatrix * scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.50f + 1.8f-dyL, -1.9f + 1.7f, -22.6f + dxx));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.07, 1.3, 0.07));
        modelTrainLine = translateMatrix * rotateYMatrix* scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);

        modelTrainLine = glm::mat4(1.0f);
        translateMatrix = glm::translate(identityMatrix, glm::vec3(75.70f-dyL, -1.9f + 1.7f, -22.6f + dxx));
        rotateYMatrix = glm::rotate(identityMatrix, glm::radians(dtheta12), glm::vec3(0.0, 1.0, 0.0));
        scaleMatrix = glm::scale(identityMatrix, glm::vec3(0.07, 1.3, 0.07));
        modelTrainLine = translateMatrix * rotateYMatrix* scaleMatrix;
        lightingShader.setMat4("model", modelTrainLine);
        drawCube(cubeVAO, lightingShader, modelTrainLine, 0.0f, 0.0f, 0.0f);



        /*if (flagR == 1)
        {
            dyL = dyL + 0.01;

        }*/
        if (flagR == 5)
        {
            dxx = dxx + 0.08;
            if (dxx >= 39)
            {
                flagR = 0;
                dxx = 0;
            }
            
        }
        /// rail project ends here ////

        // testing an object to see it can move in a circle ///
        
        //glm::mat4 modelTest = glm::mat4(1.0f);
        //translateMatrix = glm::translate(identityMatrix, glm::vec3(60.8f+cX[tiTest], -1.9f + 0.3f + 6.1 + cZ[tiTest], -0.5f));
        //scaleMatrix = glm::scale(identityMatrix, glm::vec3(3.4, 0.5, 2.5));
        //modelTest = translateMatrix * scaleMatrix;
        //lightingShader.setMat4("model", modelTest);
        //drawCube(cubeVAO, lightingShader, modelTest, 1.0f, 1.0f, 1.0f);
        //
        //////cout << ti << endl;
        //if (flagTest == 1)
        //{
        //    tiTest++;
        //    if (tiTest == 3600)
        //    {
        //        cout << "I am done" << endl;
        //        tiTest = 0;

        //    }

        //}

      
        








        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &cubeVAO);
    glDeleteVertexArrays(1, &lightCubeVAO);
    glDeleteBuffers(1, &cubeVBO);
    glDeleteBuffers(1, &cubeEBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}




// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }

    /*if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        if (rotateAxis_X) rotateAngle_X -= 0.1;
        else if (rotateAxis_Y) rotateAngle_Y -= 0.1;
        else rotateAngle_Z -= 0.1;
    }*/
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
    {
        flagNagordola = 1;

    }
    if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
    {
        flagNagordola = 0;

    }
    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS)
    {
        flagDOLNA = 1;

    }
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
    {
        flagDOLNA = 0;

    }
    if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) translate_Y += 0.001;
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) translate_Y -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) translate_X += 0.001;
    if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) translate_X -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) translate_Z += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) translate_Z -= 0.001;
    if (glfwGetKey(window, GLFW_KEY_KP_1) == GLFW_PRESS)
    {
        pointlight1.turnOn();
        
    }

    if (glfwGetKey(window, GLFW_KEY_KP_2) == GLFW_PRESS)
    {
        pointlight1.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_KP_3) == GLFW_PRESS)
    {
        pointlight3.turnOn();
    }

    if (glfwGetKey(window, GLFW_KEY_KP_4) == GLFW_PRESS)
    {
        pointlight3.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_KP_5) == GLFW_PRESS)
    {
        pointlight4.turnOn();
    }

    if (glfwGetKey(window, GLFW_KEY_KP_6) == GLFW_PRESS)
    {
        pointlight4.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_KP_7) == GLFW_PRESS)
    {
        pointlight5.turnOn();
    }

    if (glfwGetKey(window, GLFW_KEY_KP_8) == GLFW_PRESS)
    {
        pointlight5.turnOff();

    }

    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
    {
        nightflag = 1;
        pointlight1.turnOn();
        pointlight3.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS )
    {
        nightflag = 2;
        pointlight1.turnOff();
        pointlight3.turnOff();

    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) scale_X += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) scale_X -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) scale_Y += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS) scale_Y -= 0.001;
    //if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS) scale_Z += 0.001;
    //if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) scale_Z -= 0.001;

    /*if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS)
    {
        flagTest = 2;
        cout << flagTest << endl;
    }*/

    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
    {
        rotateAngle_X += 0.1;
        rotateAxis_X = 1.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 0.0;
    }
    if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        flagR = 5;
        
    }



    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS)
    {
        rotateAngle_Y += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 1.0;
        rotateAxis_Z = 0.0;
    }
    /*if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
    {
        rotateAngle_Z += 0.1;
        rotateAxis_X = 0.0;
        rotateAxis_Y = 0.0;
        rotateAxis_Z = 1.0;
    }*/

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        camera.ProcessKeyboard(FORWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        camera.ProcessKeyboard(LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        camera.ProcessKeyboard(RIGHT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
        camera.ProcessKeyboard(UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) {
        camera.ProcessKeyboard(DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS) {
        camera.ProcessKeyboard(P_UP, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
        camera.ProcessKeyboard(P_DOWN, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
        camera.ProcessKeyboard(Y_LEFT, deltaTime);
    }
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS) {
        camera.ProcessKeyboard(Y_RIGHT, deltaTime);
    }
    /*if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        camera.ProcessKeyboard(R_LEFT, deltaTime);
    }*/
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS) {
        flagRocket = 1;
    }
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
        flagRocket = 0;
    }
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
        camera.ProcessKeyboard(R_RIGHT, deltaTime);
    }
    //if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
    //{
    //    pointlight1.turnOn();
    //    pointlight3.turnOn();
    //    //pointlight4.turnOn();
    //}
    //if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
    //{
    //    pointlight1.turnOff();
    //    pointlight3.turnOff();
    //   // pointlight4.turnOff();
    //}
    
    ///new add
    if (glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS)
    {
        
        pointlight4.turnOn();
        cout << "on" << endl;
    }
    /*if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
    {
        
        pointlight4.turnOff();
        cout << "Off" << endl;
    }*/
    //newadddd
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS)
    {
        pointlight1.turnDiffuseOn();
        pointlight3.turnDiffuseOn();
        spotLight.turnDiffuseOn();
        dirLight.turnDiffuseOn();

    }
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS)
    {
        
        pointlight1.turnOff();
        pointlight3.turnOff();
        dirLight.turnOff();
        spotLight.turnOff();

    }
    if (glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS)
    {
        flag = 1.00;

    }
    if (glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS)
    {
        flagSD = 1;

    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
    {
        dirLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
    {
        dirLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS)
    {
        spotLight.turnOn();

    }
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS)
    {
        spotLight.turnOff();
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS)
    {
        pointlight1.turnAmbientOn();
        pointlight3.turnAmbientOn();
        spotLight.turnAmbientOn();
        dirLight.turnAmbientOn();
    }
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS)
    {
        pointlight1.turnSpecularOn();
        pointlight3.turnSpecularOn();
        spotLight.turnSpecularOn();
        dirLight.turnSpecularOn();
    }


 
    


}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}
unsigned int loadTexture(char const* path, GLenum textureWrappingModeS, GLenum textureWrappingModeT, GLenum textureFilteringModeMin, GLenum textureFilteringModeMax)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, textureWrappingModeS);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, textureWrappingModeT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, textureFilteringModeMin);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, textureFilteringModeMax);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Texture failed to load at path: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}


long long nCr(int n, int r)
{
    if (r > n / 2)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

//polynomial interpretation for N points
void BezierCurve(double t, float xy[2], GLfloat ctrlpoints[], int L)
{
    double y = 0;
    double x = 0;
    t = t > 1.0 ? 1.0 : t;
    for (int i = 0; i < L + 1; i++)
    {
        long long ncr = nCr(L, i);
        double oneMinusTpow = pow(1 - t, double(L - i));
        double tPow = pow(t, double(i));
        double coef = oneMinusTpow * tPow * ncr;
        x += coef * ctrlpoints[i * 3];
        y += coef * ctrlpoints[(i * 3) + 1];

    }
    xy[0] = float(x);
    xy[1] = float(y);
}

unsigned int hollowBezier(GLfloat ctrlpoints[], int L)
{
    int i, j;
    float x, y, z, r;                //current coordinates
    float theta;
    float nx, ny, nz, lengthInv;    // vertex normal


    const float dtheta = 2 * pi / ntheta;        //angular step size

    float t = 0;
    float dt = 1.0 / nt;
    float xy[2];

    for (i = 0; i <= nt; ++i)              //step through y
    {
        BezierCurve(t, xy, ctrlpoints, L);
        r = xy[0];
        y = xy[1];
        theta = 0;
        t += dt;
        lengthInv = 1.0 / r;

        for (j = 0; j <= ntheta; ++j)
        {
            double cosa = cos(theta);
            double sina = sin(theta);
            z = r * cosa;
            x = r * sina;

            coordinates.push_back(x);
            coordinates.push_back(y);
            coordinates.push_back(z);

            // normalized vertex normal (nx, ny, nz)
            // center point of the circle (0,y,0)
            nx = (x - 0) * lengthInv;
            ny = (y - y) * lengthInv;
            nz = (z - 0) * lengthInv;

            normals.push_back(nx);
            normals.push_back(ny);
            normals.push_back(nz);

            theta += dtheta;
        }
    }

    // generate index list of triangles
    // k1--k1+1
    // |  / |
    // | /  |
    // k2--k2+1

    int k1, k2;
    for (int i = 0; i < nt; ++i)
    {
        k1 = i * (ntheta + 1);     // beginning of current stack
        k2 = k1 + ntheta + 1;      // beginning of next stack

        for (int j = 0; j < ntheta; ++j, ++k1, ++k2)
        {
            // k1 => k2 => k1+1
            indices.push_back(k1);
            indices.push_back(k2);
            indices.push_back(k1 + 1);

            // k1+1 => k2 => k2+1
            indices.push_back(k1 + 1);
            indices.push_back(k2);
            indices.push_back(k2 + 1);
        }
    }

    size_t count = coordinates.size();
    for (int i = 0; i < count; i += 3)
    {
        vertices.push_back(coordinates[i]);
        vertices.push_back(coordinates[i + 1]);
        vertices.push_back(coordinates[i + 2]);

        vertices.push_back(normals[i]);
        vertices.push_back(normals[i + 1]);
        vertices.push_back(normals[i + 2]);
    }

    unsigned int bezierVAO;
    glGenVertexArrays(1, &bezierVAO);
    glBindVertexArray(bezierVAO);

    // create VBO to copy vertex data to VBO
    unsigned int bezierVBO;
    glGenBuffers(1, &bezierVBO);
    glBindBuffer(GL_ARRAY_BUFFER, bezierVBO);           // for vertex data
    glBufferData(GL_ARRAY_BUFFER,                   // target
        (unsigned int)vertices.size() * sizeof(float), // data size, # of bytes
        vertices.data(),   // ptr to vertex data
        GL_STATIC_DRAW);                   // usage

    // create EBO to copy index data
    unsigned int bezierEBO;
    glGenBuffers(1, &bezierEBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bezierEBO);   // for index data
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,           // target
        (unsigned int)indices.size() * sizeof(unsigned int),             // data size, # of bytes
        indices.data(),               // ptr to index data
        GL_STATIC_DRAW);                   // usage

    // activate attrib arrays
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // set attrib arrays with stride and offset
    int stride = 24;     // should be 24 bytes
    glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, (void*)0);
    glVertexAttribPointer(1, 3, GL_FLOAT, false, stride, (void*)(sizeof(float) * 3));

    // unbind VAO, VBO and EBO
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    return bezierVAO;
}




void railstation(unsigned int& bezierVAO, unsigned int& bezierCylinderVAO, unsigned int& cubeVAO, Shader& lightingShader, float x, float y, float z, float r, float g, float bl)
{
    glm::mat4 identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(x-10,y-2,z+20));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    glBindVertexArray(bezierVAO);
    glDrawElements(GL_TRIANGLE_FAN,(unsigned int)indices.size(),GL_UNSIGNED_INT,(void*)0);                       
    glBindVertexArray(0);

    glm::mat4 identityMatrixCurve1 = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCurve1, rotateXMatrixCurve1, rotateYMatrixCurve1, rotateZMatrixCurve1, scaleMatrixCurve1, modelforCurve1;
    translateMatrixCurve1 = glm::translate(identityMatrixCurve1, glm::vec3(58.0f, -1.9f, -20.5f));
    rotateXMatrixCurve1 = glm::rotate(identityMatrixCurve1, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve1 = glm::rotate(identityMatrixCurve1, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve1 = glm::rotate(identityMatrixCurve1, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve1 = glm::scale(identityMatrixCurve1, glm::vec3(3,2.5,3));
    modelforCurve1 = translateMatrixCurve1 * rotateXMatrixCurve1 * rotateYMatrixCurve1 * rotateZMatrixCurve1 * scaleMatrixCurve1;
    lightingShader.setMat4("model", modelforCurve1);
    glBindVertexArray(bezierCylinderVAO);
    glDrawElements(GL_TRIANGLE_FAN,(unsigned int)indices.size(),GL_UNSIGNED_INT,(void*)0);                       
    glBindVertexArray(0);

    glm::mat4 identityMatrixCube = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(61, y+3, -8.0f));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCube = glm::rotate(identityMatrixCube, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(7, 0.5, 10));
    modelforCube = translateMatrixCube * rotateXMatrixCube * rotateYMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    drawCube(cubeVAO, lightingShader, modelforCube, 1.0, 1.0, 1.0);


}
void nagordola(unsigned int& bezierVAO, unsigned int& cubeVAO, Shader& lightingShader, Sphere &sphere, vector<float>& cx, vector<float>& cz,
    float tx1, float ty1, float tz1, float sx1, float sy1, float sz1){

    Cube cube = Cube();
    glm::mat4 identityMatrixSphere = glm::mat4(1.0f);
    glm::mat4 translateMatrixSphere, rotateXMatrixSphere, rotateYMatrixSphere, rotateZMatrixSphere, scaleMatrixSphere, modelforSphere;
    translateMatrixSphere = glm::translate(identityMatrixSphere, glm::vec3(38.0f+tx1+cx[0], 7.8f +0.8, tz1 - 22.5f));
    scaleMatrixSphere = glm::scale(identityMatrixSphere, glm::vec3(0.5,0.5,0.5));
    modelforSphere = translateMatrixSphere * scaleMatrixSphere;
    lightingShader.setMat4("model", modelforSphere);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    sphere.drawSphere(lightingShader, modelforSphere);

    identityMatrixSphere = glm::mat4(1.0f);
    translateMatrixSphere = glm::translate(identityMatrixSphere, glm::vec3(38.0f + tx1 + cx[0], 7.8f +0.8, tz1 - 19.5f));
    scaleMatrixSphere = glm::scale(identityMatrixSphere, glm::vec3(0.5, 0.5, 0.5));
    modelforSphere = translateMatrixSphere * scaleMatrixSphere;
    lightingShader.setMat4("model", modelforSphere);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    sphere.drawSphere(lightingShader, modelforSphere);


    glm::mat4 identityMatrixCube = glm::mat4(1.0f);
    glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.5, 0.5, -3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube,glm::radians(-30.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 22.8f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-30.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-330.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 22.8f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-330.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(38.0f + tx1 + cx[0], 7.6f + 1.0, tz1 - 20.7f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(0.0f + rtheta), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(5.5, 0.15, 0.05));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);


    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(38.0f + tx1 + cx[0], 7.6f + 1.0, tz1 - 20.7f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(90.0f+rtheta), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(5.5, 0.15, 0.05));
    modelforCube = translateMatrixCube*rotateZMatrixCube*scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(38.0f + tx1 + cx[0], 7.6f + 1.0, tz1 - 20.7f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(270.0f+rtheta), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(5.5, 0.15, 0.05));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);
    
    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(38.0f + tx1 + cx[0], 7.6f + 1.0, tz1 - 20.7f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(180.0f+rtheta), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(5.5, 0.15, 0.05));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    



    
    glm::mat4 identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1+38.0f + cx[t]+ cx[0],ty1+5.0f+cz[t]+cz[0], tz1-20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3+sx1, 2.5+sy1, 3+sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    glBindVertexArray(bezierForNagordola);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1+38.0f+cx[ti]+cx[0],ty1+5.0f+cz[ti]+cz[0], tz1-20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3 + sx1, 2.5 + sy1, 3 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    glBindVertexArray(bezierForNagordola);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1+38.0f + cx[tii] + cx[0], ty1+5.0f + cz[tii] + cz[0], tz1-20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3 + sx1, 2.5 + sy1, 3 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    glBindVertexArray(bezierForNagordola);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1+38.0f + cx[0] + cx[tiii],ty1+ 5.0f + cz[3599] + cz[tiii], tz1-20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3 + sx1, 2.5 + sy1, 3 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    glBindVertexArray(bezierForNagordola);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);


    if (flagNagordola)
    {
        tiii++;
        if (tiii == 3600)
        {
            tiii = 0;
        }
        tii++;
        if (tii == 3600)
        {
            tii = 0;
        }
        ti++;
        if (ti == 3600)
        {
            ti = 0;
        }
        t++;
        if (t == 3600)
        {
            t = 0;
        }
        rtheta = 0.1 + rtheta;

    }
    else if ( flagNagordola == 0)
    {
        tiii = 3599;
        tii = 2699;
        ti = 1799;
        t = 899;
        rtheta = 0.0;
    }

    
    

    
}

void tree(unsigned int& bezierTree, unsigned int& bezierMatha, unsigned int& bezierCylinder, unsigned int& cubeVAO, Shader &lightingShader, Sphere& sphere,float tx1, float ty1, float tz1, float sx1, float sy1, float sz1)
{
    Cube cube = Cube();
    glm::mat4 identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1 + 34.0f, ty1 + 1.0f, tz1 - 20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3 + sx1, 5 + sy1, 3 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierTree);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1 + 34.0f, ty1 - 1.0f, tz1 - 20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4 + sx1, 5 + sy1, 4 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierTree);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1 + 34.0f, ty1 -3.0f, tz1 - 20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(5 + sx1, 5 + sy1, 5 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierTree);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1 + 34.0f, ty1 + 2.0f, tz1 - 20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3 + sx1, 5 + sy1, 3 + sz1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 1.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(tx1 + 33.9f, ty1 - 14.0f, tz1 - 20.5f));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(1.0f, 1.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(1, 10.0, 1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.647f, 0.165f, 0.165f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.647f, 0.165f, 0.165f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCylinder);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

}
void rocketDriver(unsigned int &bezierCylinderVAO,unsigned int &bezierCyCurve, unsigned int& bezierMatha, unsigned int& cubeVAO, Shader& lightingShader,
    vector<float>& cx1, vector<float>& cz1,
    float txr, float tyr, float tzr,float ctz
)
{
    //glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix,modelLathi;
    //modelLathi = glm::mat4(1.0f);
    //identityMatrix = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 29.5+txr, -2.5f + 4.5f+tyr, -7.8f - 6.0f+tzr+ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(0.25f, 0.25f, 15.8f));
    //modelLathi = translateMatrix * rotateYMatrix * rotateXMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 0.0f, 1.0f);



    //modelLathi = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 30 + txr, -2.5f + 4.5f + tyr, -7.8f - 6.0f + tzr+ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(60.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(0.25f, 0.26f, 15.8f));
    //modelLathi = translateMatrix *rotateYMatrix * rotateXMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 0.0f, 1.0f);



    //modelLathi = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 30.5+txr, -2.5f + 4.5f+tyr, -7.8f - 6.0f+tzr+ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(120.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(0.25f, 0.26f, 15.8f));
    //modelLathi = translateMatrix * rotateYMatrix * rotateXMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 0.0f, 1.0f);

    //modelLathi = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 30.0 + txr, -2.5f + 4.5f + tyr, -7.8f - 6.0f + tzr+ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f+dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(180.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(0.25f, 0.26f, 15.8f));
    //modelLathi = translateMatrix  *rotateYMatrix * rotateXMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 0.0f, 1.0f);


    //modelLathi = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 29.5 + txr, -2.5f + 4.5f + tyr, -7.8f - 6.0f + tzr+ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(240.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(0.25f, 0.26f, 15.8f));
    //modelLathi = translateMatrix * rotateYMatrix * rotateXMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 0.0f, 1.0f);

    //modelLathi = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 29.0 + txr, -2.5f + 4.5f + tyr, -7.8f - 6.0f + tzr+ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(300.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(0.25f, 0.26f, 15.8f));
    //modelLathi = translateMatrix * rotateYMatrix * rotateXMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 0.0f, 1.0f);

    //glm :: mat4 modelLathi1 = glm::mat4(1.0f);
    //translateMatrix = glm::translate(modelLathi, glm::vec3(-10.5f + 25.0 + txr, -2.5f  + tyr, -7.8f - 6.0f + tzr + ctz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(300.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    ////rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    //scaleMatrix = glm::scale(modelLathi, glm::vec3(2.5f, 1.0f, 2.8f));
    //modelLathi1 = translateMatrix * rotateYMatrix * rotateXMatrix * scaleMatrix;
    ////modelLathi = translateMatrix *  scaleMatrix;
    //lightingShader.setMat4("model", modelLathi1);
    //drawCube(cubeVAO, lightingShader, modelLathi1, 1.0f, 0.0f, 1.0f);

    if (flagRocket == 1)
    {
        if (dthetaX <= -40.0 && irt>=7.6)
        {
            dthetaY = dthetaY - 0.1;
            rocketI = rocketI + 1;
            if (rocketI == 720)
            {
                rocketI = 0;
            }

        }
        if (dthetaX >= -40.0)
        {
            dthetaX = dthetaX - 0.06;

        }
        if (irt <= 7.6)
        {
            irt = irt + 0.0110;
        }
        if (irt <= 2.5)
        {
            irtz = irtz + 0.01;
        }

    }
    else 
    {
        dthetaY = 0.0;
        dthetaX = 0.0;

    }
    
    glm::mat4 identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f-30,-5.0f, 20.5f-15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(15 , 2.5 , 15));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCylinderVAO);
    glDrawElements(GL_TRIANGLE_FAN, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(5, 15, 5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f,0.0f,0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCylinderVAO);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f+16.5f, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4, 10, 4));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCylinderVAO);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f + 16.5f, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3.8, 10, 3.8));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCyCurve);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f + 24.0f, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 10, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f); 
    glBindVertexArray(bezierCylinderVAO);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f + 24.0f, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 10, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCyCurve);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f + 24.0f + 16.0, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.69, 0.82, 0.941));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.69, 0.82, 0.941));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCyCurve);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);


    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 30, -16.0f + 24.0f+3.0, 20.5f - 15+ctz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 10, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0,0,1));
    lightingShader.setVec3("material.diffuse", glm::vec3(0, 0, 1));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    //cube
   
    //glm::mat4 identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    //translateMatrixCube = glm::translate(identityMatrix, glm::vec3(-10.5f + 29.0 - 6.5 + txr+cx1[0] + cx1[rt], -2.5f + 3.0f + 5.0, tzr-13.5 + cz1[0] + cz1[rt]+ctz));
    //scaleMatrixCube = glm::scale(identityMatrix, glm::vec3(3, 2, 3));
    //modelforCube = translateMatrixCube * scaleMatrixCube;
    //lightingShader.setMat4("model", modelforCube);
    //drawCube(cubeVAO, lightingShader, modelforCube, 1.0f, 1.0f, 1.0f);
    ////cout << irt << endl;

    //identityMatrixCube = glm::mat4(1.0f);
    ////glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    //translateMatrixCube = glm::translate(identityMatrix, glm::vec3(-10.5f + 28.0 - 6.5 + txr + cx1[0] + cx1[rti], -2.5f + 3.0f + 5.0, tzr-13.5 + +cz1[0] + cz1[rti]+ctz));
    //scaleMatrixCube = glm::scale(identityMatrix, glm::vec3(3, 2, 3));
    //modelforCube = translateMatrixCube * scaleMatrixCube;
    //lightingShader.setMat4("model", modelforCube);
    //drawCube(cubeVAO, lightingShader, modelforCube, 1.0f, 1.0f, 1.0f);


    //identityMatrixCube = glm::mat4(1.0f);
    ////glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    //translateMatrixCube = glm::translate(identityMatrix, glm::vec3(-10.5f + 29.0 - 6.5 + txr + cx1[0] + cx1[rtii], -2.5f + 3.0f + 5.0,  -4.0+tzr-13.5 + cz1[0] + cz1[rtii]+ctz));
    //scaleMatrixCube = glm::scale(identityMatrix, glm::vec3(3, 2, 3));
    //modelforCube = translateMatrixCube * scaleMatrixCube;
    //lightingShader.setMat4("model", modelforCube);
    //drawCube(cubeVAO, lightingShader, modelforCube, 1.0f, 1.0f, 1.0f);

    //identityMatrixCube = glm::mat4(1.0f);
    ////glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    //translateMatrixCube = glm::translate(identityMatrix, glm::vec3(-10.5f + 28.0-6.5 + txr + cx1[0]+cx1[rtiii], -2.5f + 3.0f + 5.0,  tzr-13.5 + cz1[0] + cz1[rtiii]+ctz));
    //scaleMatrixCube = glm::scale(identityMatrix, glm::vec3(3, 2, 3));
    //modelforCube = translateMatrixCube * scaleMatrixCube;
    //lightingShader.setMat4("model", modelforCube);
    //drawCube(cubeVAO, lightingShader, modelforCube, 1.0f, 1.0f, 1.0f);
    /*rt++;
    if (rt == 3600)
    {
        rt = 0;
    }
    rti++;
    if (rti == 3600)
    {
        rti = 0;
    }
    rtii++;
    if (rtii == 3600)
    {
        rtii = 0;
    }
    rtiii++;
    if (rtiii == 3600)
    {
        rtiii = 0;
    }*/
    /*rt++;
    if (rt == 3600)
    {
        rt = 0;
    }
    rtii++;
    if (rtii == 3600)
    {
        rtii = 0;
    }*/

  
    
}

void dolna(unsigned int& bezierCylinder,unsigned int& bezierDolna ,unsigned int& bezierMatha, unsigned int& cubeVAO, Shader& lightingShader,
    vector<float>& cx1, vector<float>& cz1,
    float cmnx, float cmny, float cmnz
)
{
    glm::mat4 identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(37.5f + cmnx, 8.0f + cmny, 8.5f + cmnz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(1.0f, 1.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(20, 0.8, 20));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1, 0.459, 0));
    lightingShader.setVec3("material.diffuse", glm::vec3(1, 0.459, 0));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCylinderVAO);
    glDrawElements(GL_TRIANGLE_FAN, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(37.5f + cmnx,  -6.5+cmny, 8.5f + cmnz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(1.0f, 1.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(10, 10.0, 10));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.839, 0.827, 0.961));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.839, 0.827, 0.961));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLE_FAN, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);


    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrixCurve, rotateXMatrixCurve, rotateYMatrixCurve, rotateZMatrixCurve, scaleMatrixCurve, modelforCurve;
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(37.5f + cmnx, -16.5 + cmny, 8.5f + cmnz));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(1.0f, 1.0f, 1.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(1.0f, 1.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(1, 15.0, 1));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(0.522f, 0.804f, 0.969f));
    lightingShader.setVec3("material.diffuse", glm::vec3(0.522f, 0.804f, 0.969f));
    lightingShader.setVec3("material.specular", glm::vec3(0.0f, 0.0f, 0.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierCylinder);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);


    glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(28.2f + cmnx, -2.5f + cmny, 2.5f + cmnz));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(19, 2.0, 14));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.969, 0.792, 0.671);



    //1st dolna
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f-2.5  + cmnx + cx1[0] + cx1[di], -3.0f + cmny, 9.5f+ cmnz + cz1[0] + cz1[di]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierDolna);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0]+cx1[di], -3.5f + cmny, 9.5f + cmnz + cz1[0]+cz1[di]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4.5, 3.5, 4.5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(33.8f + cmnx+cx1[0] + cx1[di] - 2.5, 1.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[di]));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.15f, 7.5f, 0.15f));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    //1st dolna ends


     //2nd dolna
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0]+cx1[dii], -3.0f + cmny, 9.5f + cmnz + cz1[0]+cz1[dii]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierDolna);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0]+cx1[dii], -3.5f + cmny, 9.5f + cmnz + cz1[0]+cz1[dii]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4.5, 3.5, 4.5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(33.8f + cmnx + cx1[0]+cx1[dii] - 2.5, 1.5f + cmny, 9.5f + cmnz + cz1[0]+cz1[dii]));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.15f, 7.5f, 0.15f));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    //2nd dolna ends

     //3rd dolna
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[diii], -3.0f + cmny, 9.5f + cmnz + cz1[0] + cz1[diii]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierDolna);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[diii], -3.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[diii]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4.5, 3.5, 4.5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(33.8f + cmnx + cx1[0] + cx1[diii] - 2.5, 1.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[diii]));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.15f, 7.5f, 0.15f));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    //3rd dolna ends

     //4nd dolna
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[diiv], -3.0f + cmny, 9.5f + cmnz + cz1[0] + cz1[diiv]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierDolna);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[diiv], -3.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[diiv]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4.5, 3.5, 4.5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(33.8f + cmnx + cx1[0] + cx1[diiv] - 2.5, 1.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[diiv]));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.15f, 7.5f, 0.15f));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    //4nd dolna ends

     //5nd dolna
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[dv], -3.0f + cmny, 9.5f + cmnz + cz1[0] + cz1[dv]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierDolna);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[dv], -3.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[dv]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4.5, 3.5, 4.5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(33.8f + cmnx + cx1[0] + cx1[dv] - 2.5, 1.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[dv]));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.15f, 7.5f, 0.15f));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    //5nd dolna ends

    //6nd dolna
    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[dvi], -3.0f + cmny, 9.5f + cmnz + cz1[0] + cz1[dvi]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(3, 2.5, 3));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 1.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierDolna);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrixCurve = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    translateMatrixCurve = glm::translate(identityMatrixCurve, glm::vec3(34.0f - 2.5 + cmnx + cx1[0] + cx1[dvi], -3.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[dvi]));
    rotateXMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_X), glm::vec3(1.0f, 0.0f, 0.0f));
    rotateYMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Y), glm::vec3(0.0f, 1.0f, 0.0f));
    rotateZMatrixCurve = glm::rotate(identityMatrixCurve, glm::radians(rotateAngle_Z), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrixCurve = glm::scale(identityMatrixCurve, glm::vec3(4.5, 3.5, 4.5));
    modelforCurve = translateMatrixCurve * rotateXMatrixCurve * rotateYMatrixCurve * rotateZMatrixCurve * scaleMatrixCurve;
    lightingShader.setMat4("model", modelforCurve);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 1.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 25.0f);
    glBindVertexArray(bezierMatha);
    glDrawElements(GL_TRIANGLES, (unsigned int)indices.size(), GL_UNSIGNED_INT, (void*)0);
    glBindVertexArray(0);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(33.8f + cmnx + cx1[0] + cx1[dvi] - 2.5, 1.5f + cmny, 9.5f + cmnz + cz1[0] + cz1[dvi]));
    //rotateXMatrix = glm::rotate(identityMatrix, glm::radians(50.0f + dthetaX), glm::vec3(1.0f, 0.0f, 0.0f));
    //rotateYMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 1.0f, 0.0f));
    //rotateZMatrix = glm::rotate(identityMatrix, glm::radians(00.0f + dthetaY), glm::vec3(0.0f, 0.0f, 1.0f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.15f, 7.5f, 0.15f));
    modelLathi = translateMatrix * scaleMatrix;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    //6nd dolna ends
    if (flagDOLNA == 1)
    {
        di++;
        if (di == 3600)
        {
            di = 0;
        }
        dii++;
        if (dii == 3600)
        {
            dii = 0;
        }
        diii++;
        if (diii == 3600)
        {
            diii = 0;
        }
        diiv++;
        if (diiv == 3600)
        {
            diiv = 0;
        }
        dv++;
        if (dv == 3600)
        {
            dv = 0;
        }
        dvi++;
        if (dvi == 3600)
        {
            dvi = 0;
        }
    }
    else if (flagDOLNA == 0)
    {
        di = 599;
        dii = 1199;
        diii = 1799;
        diiv = 2399;
        dv = 2999;
        dvi = 3599;
    }
    
}

void bera(unsigned int& bezierMatha, unsigned int& cubeVAO, Cube& cube1,Shader &lightingShader,Shader &ligthingwithtexture, float tx, float ty, float tz)
{
    glm :: mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(tx + 34.0f, ty - 2.0f, tz - 11.5f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.3f, 4.5f, 0.3f));
    modelLathi = translateMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    cube1.drawCubeWithTexture(ligthingwithtexture, modelLathi);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(tx + 34.0f, ty - 2.0f, tz - 11.5f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(7.0f, 0.1f, 0.1f));
    modelLathi = translateMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    cube1.drawCubeWithTexture(ligthingwithtexture, modelLathi);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(tx + 34.0f, ty +0.0f, tz - 11.5f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(7.0f, 0.1f, 0.1f));
    modelLathi = translateMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    cube1.drawCubeWithTexture(ligthingwithtexture, modelLathi);

    identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    //glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(tx + 34.0f, ty +2.0f, tz - 11.5f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(7.0f, 0.1f, 0.1f));
    modelLathi = translateMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    cube1.drawCubeWithTexture(ligthingwithtexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    identityMatrix = glm::mat4(1.0f);
    translateMatrix = glm::translate(modelLathi, glm::vec3(tx + 41.0f, ty - 2.0f, tz - 11.5f));
    scaleMatrix = glm::scale(modelLathi, glm::vec3(0.3f, 4.5f, 0.3f));
    modelLathi = translateMatrix * scaleMatrix;
    //lightingShader.setMat4("model", modelLathi);
    //drawCube(cubeVAO, lightingShader, modelLathi, 0.0f, 0.0f, 0.0f);
    cube1.drawCubeWithTexture(ligthingwithtexture, modelLathi);
   

}
void singleDolna(unsigned int& cubeVAO, Cube& cube1, Shader& lightingShader, Shader& ligthingwithtexture, float tx, float ty, float tz)
{
    Cube cube = Cube();
    glm::mat4 identityMatrixCube = glm::mat4(1.0f);
    glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx, ty+10.5, tz+10.0 ));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-15.0f), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.20, -9.5, .20));
    modelforCube = translateMatrixCube * rotateXMatrixCube *scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(15.0f), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.20, -9.5, .20));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f+7 + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-15.0f), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.20, -9.5, .20));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);


    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f+7 + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(15.0f), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.20, -9.5, .20));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    //uprer handle
    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.9f + 7 + tx, ty+10.5, tz + 10.0));
    //rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(15.0f), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(-7, 0.20, 0.20));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    //dolna seat handle
    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 1 + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-15.0f+dseatheta), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.15, -6.5, .15));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f,0.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);


    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 1 + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(15.0f+dseatheta), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.15, -6.5, .15));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 6 + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-15.0f+dseatheta), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.15, -6.5, .15));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);


    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 6 + tx, ty+10.5, tz + 10.0));
    rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(15.0f+dseatheta), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(.15, -6.5, .15));
    modelforCube = translateMatrixCube * rotateXMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    //dolna seat
    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 0.5 + tx , ty+4.0, tz + 8.0 ));
    //rotateXMatrixCube = glm::rotate(identityMatrixCube, glm::radians(dseatheta), glm::vec3(1.0, 0.0, 0.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(6.0, 0.20, 4.00));
    modelforCube = translateMatrixCube  * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    //if (flagsd == 2)
    //{
    //    dseatheta = dseatheta - 0.07;
    //    if (dseatheta <= -6.0)
    //    {
    //        flagsd = -2;
    //    }
    //}
    //if (flagsd == -2)
    //{
    //    dseatheta = dseatheta + 0.07;
    //    //cout << dseatheta << endl;
    //    if (dseatheta >= 6.0)
    //    {
    //        flagsd = 2;
    //    }

    //}

    //if (flagsd1 == 2)
    //{
    //    dseatheta100 = dseatheta100 - (0.008);
    //    cout << "hello" << endl;
    //    if (dseatheta100 <= -0.30)
    //    {
    //        flagsd1 = -2;
    //    }
    //}
    //if (flagsd1 == -2)
    //{
    //    dseatheta100 = dseatheta100 + 1.00;
    //    
    //    /*cout << dseatheta100 << endl;
    //    if (dseatheta100 >= 0.3)
    //    {
    //        flagsd1 = 2;
    //    }*/

    //}
    

    






}
void tamim(unsigned int& bezierCylinderVAO, unsigned int& bezierCyCurve, unsigned int& bezierMatha, unsigned int& cubeVAO, Shader& lightingShader, Shader& lightingShaderWithTexture,Cube &cube2,
    vector<float>& cx1, vector<float>& cz1,
    float txr, float tyr, float tzr, float ctz, glm::mat4 altogether
)
{

    //glm::mat4 identityMatrix = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    /*modelLathi = transform(0.0, 0.0, 0.0, 50.0+ dthetaX, 0.0, 0.0, 0.25f, 0.25f, 15.8f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 0.0f, 1.0f);*/


    modelLathi = transform(0.0, 0.0, 0.0, 50.0+dthetaX , 0.0, 0.0, 0.25f, 0.75f, 15.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 0.0+dthetaY , 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 0.0f, 0.0f, 0.0f);
   

    modelLathi = transform(0.0, 0.0, 0.0, 50.0 + dthetaX, 0.0, 0.0, 0.25f, 0.75f, 15.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 90.0 + dthetaY, 0.0, 1,1,1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 1.0f, 1.0f);

    modelLathi = transform(0.0, 0.0, 0.0, 50.0 + dthetaX, 0.0, 0.0, 0.25f, 0.75f, 15.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 180.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 0.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0, 0.0, 0.0, 50.0 + dthetaX, 0.0, 0.0, 0.25f, 0.75f, 15.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 270.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 1.0f, 1.0f);
    lightingShaderWithTexture.use();

    //object in matha1.........................................
    modelLathi = transform(0.0-1.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 7.0f, 0.2f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 0.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 0.0f, 0.0f, 0.0f);
    //cube2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 9.00 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 0.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 12.50 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 0.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0 - 1.75+6.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 0.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 0.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0 - 1.75, -12.98 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, -50.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 0.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 1.0f, 1.0f);
    ///modelmatha.......................................................................


    //>>>>>>>>>>>>>>modelMath3<<<<<<<<<<<<<<<<<<<<<<<<//
    modelLathi = transform(0.0 - 1.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 7.0f, 0.2f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 180.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 0.0f, 0.0f, 0.0f);
    //cube2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 9.00 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 180.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 12.50 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 180.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0 - 1.75 + 6.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 180.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 1.0f, 1.0f, 0.0f);

    modelLathi = transform(0.0 - 1.75, -12.98 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, -50.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 180.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether * modelLathi, 0.0f, 1.0f, 1.0f);

    ///modelmatha



    //object in matha2

    modelLathi = transform(0.0 - 1.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 7.0f, 0.2f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 0.0f, 0.0f, 0.0f);
    //cube2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 9.00 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 0.0f, 1.0f, 1.0f);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 12.50 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 0.0f, 1.0f, 1.0f);

    modelLathi = transform(0.0 - 1.75 + 6.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 0.0f, 1.0f, 0.0f);

    modelLathi = transform(0.0 - 1.75, -12.98 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, -50.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, 90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 1.0f, 1.0f, 0.0f);

    ///modelmatha

    //object in matha4
    modelLathi = transform(0.0 - 1.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 7.0f, 0.2f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, -90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 0.0f, 0.0f, 0.0f);
    //cube2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 9.00 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, -90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 1.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0, -13.1035 + dyytamim, 12.50 + dxxtamim, -90.0, 00.0, 0.0, 5.0f, 0.2f, 1.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, -90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 1.0f, 0.0f, 0.0f);

    modelLathi = transform(0.0 - 1.75 + 6.75, -13.1035 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, 0.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, -90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 0.0f, 0.0f, 1.0f);

    modelLathi = transform(0.0 - 1.75, -12.98 + dyytamim, 9.00 + dxxtamim, 0.0, 0.0, -50.0, 0.20f, 3.0f, 3.5f);
    //modelLathi = transform(0.0, -12.1035, 10.15, 0.0, 0.0, 0.0, 1.5f, 0.5f, 1.8f);
    modelLathi = transform(0.0, 0.0, 0.0, 0.0, -90.0 + dthetaY, 0.0, 1, 1, 1) * modelLathi;
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, altogether* modelLathi, 1.0f, 1.0f, 1.0f);
    ///modelmatha

    

    if (flagRocket == 1)
    {
        if (dthetaX <= -40.0 && irt >= 7.6)
        {
            dthetaY = dthetaY - 0.4;
            rocketI = rocketI + 1;
            if (rocketI == 720)
            {
                rocketI = 0;
            }

        }
        if (dthetaX >= -40.0)
        {
            dthetaX = dthetaX - 0.06;
            dyytamim = 15.8 * glm::sin(glm::radians(-dthetaX));
            dxxtamim = dxxtamim + 0.0155;
            //dyytamim = dyytamim + 0.0152;



        }
        if (irt <= 7.6)
        {
            irt = irt + 0.0110;
        }
        if (irt <= 2.5)
        {
            irtz = irtz + 0.01;
        }

    }
    else
    {
        dthetaY = 0.0;
        dthetaX = 0.0;
        dyytamim = 0.0;
        dxxtamim = 0.0;

    }


}

void coffeeshop(unsigned int& cubeVAO, Cube& coffee, Cube& coffee1, Cube& coffee2,Shader& lightingShader, Shader& lightingShaderWithTexture, float txC, float tyC, float tzC)
{
    glm::mat4 translateMatrix, rotateXMatrix, rotateYMatrix, rotateZMatrix, scaleMatrix, modelLathi;
    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(32.0, -1.9, -25.0, 0.0, 0.0, 0.0, 20.0f, 10.00f, 1.0f);
    coffee1.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(32.0, -1.9, -18.0, 0.0, 0.0, 0.0, 19.50f, 4.00f, 3.0f);
    /*lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);*/
    coffee.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(35.0, -1.9+10, -18.0, 0.0, 0.0, 0.0, 12.00f, 4.00f, 0.50f);
    /*lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);*/
    coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(32.0, -1.9+10-0.5, -25.00, 0.0, 0.0, 0.0, 19.50f, 0.50f, 10.0f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(32.0, -1.9, -25.10, 0.0, -90.0, 0.0, 10.0f, 10.00f, 0.50f);
    /*lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 0.0f, 1.0f, 1.0f);*/
    coffee1.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(52.0, -1.9, -25.0, 0.0, -90.0, 0.0, 10.0f, 10.00f, 0.50f);
    coffee1.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(38.0, -1.9+3, -12.0, 0.0, -90.0, 0.0, 8.50f, 0.50f, 4.0f);
    /*lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);*/
    coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(35.0, -1.9, -12.0, 0.0, 00.0, 0.0, 2.50f, 3.00f, 0.50f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(35.0, -1.9, -4.50, 0.0, 00.0, 0.0, 2.50f, 3.00f, 0.50f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);


    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(34.0, -1.9 + 1.5, -12.0+1.00+1.00, 0.0, -90.0, 0.0, 4.50f, 0.50f, 2.0f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(34.0, -1.9, -11.0+1.00+1.00, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(34.0, -1.9, -9.0+1.00+1.00, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(41.0, -1.9 + 1.5, -12.0 + 1.00 + 1.00, 0.0, -90.0, 0.0, 4.50f, 0.50f, 2.0f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(41.0, -1.9, -11.0 + 1.00 + 1.00, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(41.0, -1.9, -9.0 + 1.00 + 1.00, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);









    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(48.0, -1.9 + 3, -12.0, 0.0, -90.0, 0.0, 8.50f, 0.50f, 4.0f);
    /*lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);*/
    coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0, -1.9, -12.0, 0.0, 00.0, 0.0, 2.50f, 3.00f, 0.50f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0, -1.9, -4.50, 0.0, 00.0, 0.0, 2.50f, 3.00f, 0.50f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0, -1.9 + 1.5, -12.0+2.0, 0.0, -90.0, 0.0, 4.50f, 0.50f, 2.0f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader,modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0, -1.9 , -11.0+2.0, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0, -1.9, -9.0+2.0, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0+5.0, -1.9 + 1.5, -12.0 + 2.0, 0.0, -90.0, 0.0, 4.50f, 0.50f, 2.0f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0+5.0, -1.9, -11.0 + 2.0, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    modelLathi = glm::mat4(1.0f);
    modelLathi = transform(45.0+5.0, -1.9, -9.0 + 2.0, 0.0, -90.0, 0.0, 0.50f, 2.00f, 2.00f);
    lightingShader.setMat4("model", modelLathi);
    drawCube(cubeVAO, lightingShader, modelLathi, 1.0f, 1.0f, 1.0f);
    //coffee2.drawCubeWithTexture(lightingShaderWithTexture, modelLathi);

    


}
void sleeper(unsigned int& bezierVAO, unsigned int& cubeVAO, Shader& lightingShader, Sphere& sphere, vector<float>& cx, vector<float>& cz,
    float tx1, float ty1, float tz1, float sx1, float sy1, float sz1) {

    Cube cube = Cube();
    glm::mat4 identityMatrixSphere = glm::mat4(1.0f);
    glm::mat4 translateMatrixSphere, rotateXMatrixSphere, rotateYMatrixSphere, rotateZMatrixSphere, scaleMatrixSphere, modelforSphere;
    translateMatrixSphere = glm::translate(identityMatrixSphere, glm::vec3(38.0f + tx1 + cx[0], 7.8f + 0.8, tz1 - 22.5f));
    scaleMatrixSphere = glm::scale(identityMatrixSphere, glm::vec3(0.5, 0.5, 0.5));
    modelforSphere = translateMatrixSphere * scaleMatrixSphere;
    lightingShader.setMat4("model", modelforSphere);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    sphere.drawSphere(lightingShader, modelforSphere);

    identityMatrixSphere = glm::mat4(1.0f);
    translateMatrixSphere = glm::translate(identityMatrixSphere, glm::vec3(38.0f + tx1 + cx[0], 7.8f + 0.8, tz1 - 19.5f));
    scaleMatrixSphere = glm::scale(identityMatrixSphere, glm::vec3(0.5, 0.5, 0.5));
    modelforSphere = translateMatrixSphere * scaleMatrixSphere;
    lightingShader.setMat4("model", modelforSphere);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    sphere.drawSphere(lightingShader, modelforSphere);


    glm::mat4 identityMatrixCube = glm::mat4(1.0f);
    glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.5, 0.5, -3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f+0.5 + tx1 + cx[0], 7.0f + 0.8, tz1 - 19.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.15, 0.15, -3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 1.8 + tx1 + cx[0], 7.0f - 1.6, tz1 - 19.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.15, 0.15, -3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 2.9 + tx1 + cx[0], 7.0f - 3.2, tz1 - 19.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.15, 0.15, -3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);


    identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + 3.9 + tx1 + cx[0], 7.0f - 4.8, tz1 - 19.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.15, 0.15, -3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);











    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-30.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);


    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-30.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.050, -10.5, -2.90));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 22.8f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-30.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 19.5f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-330.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    //glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(37.8f + tx1 + cx[0], 7.6f + 0.8, tz1 - 22.8f));
    rotateZMatrixCube = glm::rotate(identityMatrixCube, glm::radians(-330.0f), glm::vec3(0.0, 0.0, 1.0));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.30, -10.5, 0.30));
    modelforCube = translateMatrixCube * rotateZMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

 



    


}

void lamp(unsigned int& cubeVAO, Shader& lightingShader, float tx1, float ty1, float tz1, float sx1, float sy1, float sz1)
{
    Sphere sphere = Sphere(1.0f,  36,  18,  glm::vec3(1.0f, 1.0f, 1.0f),  glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.5f, 0.5f, 0.5f),  32.0f);
    Cube cube = Cube();
    glm::mat4 identityMatrixSphere = glm::mat4(1.0f);
    glm::mat4 translateMatrixSphere, rotateXMatrixSphere, rotateYMatrixSphere, rotateZMatrixSphere, scaleMatrixSphere, modelforSphere;
    translateMatrixSphere = glm::translate(identityMatrixSphere, glm::vec3(-11.0f+0.1+tx1, 8.5f+ty1, 23.5f+tz1));
    scaleMatrixSphere = glm::scale(identityMatrixSphere, glm::vec3(1.0, 1.0, 1.0));
    modelforSphere = translateMatrixSphere * scaleMatrixSphere;
    lightingShader.setMat4("model", modelforSphere);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    sphere.drawSphere(lightingShader, modelforSphere);

    glm::mat4 identityMatrixCube = glm::mat4(1.0f);
    glm::mat4 translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(-11.250f+0.15+tx1, 8.5f+ty1, 23.5f+tz1));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(0.5, -7.5, 0.5));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(-11.250f -1.20+tx1, 7.70f+ty1, 21.5f+tz1));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(3.0, -0.25, 3.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    /*identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(-11.250f - 1.60, 7.70f-5.25+1-5, 21.5f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(4.0, -0.25, 4.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);

    identityMatrixCube = glm::mat4(1.0f);
    translateMatrixCube, rotateXMatrixCube, rotateYMatrixCube, rotateZMatrixCube, scaleMatrixCube, modelforCube;
    translateMatrixCube = glm::translate(identityMatrixCube, glm::vec3(-11.250f - 2.20, 7.70f - 4.60-5.0, 20.50f));
    scaleMatrixCube = glm::scale(identityMatrixCube, glm::vec3(5.0, -0.25, 5.0));
    modelforCube = translateMatrixCube * scaleMatrixCube;
    lightingShader.setMat4("model", modelforCube);
    lightingShader.use();
    lightingShader.setVec3("material.ambient", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.diffuse", glm::vec3(1.0f, 0.0f, 0.0f));
    lightingShader.setVec3("material.specular", glm::vec3(1.0f, 1.0f, 1.0f));
    lightingShader.setFloat("material.shininess", 32.0f);
    cube.setMaterialisticProperty(glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f), 32.0f);
    cube.drawCubeWithMaterialisticProperty(lightingShader, modelforCube);*/
}