#include "textureLoader.h"
#include "globals.h"
#include "stb_image.h"
#include <GL/gl.h>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "acfutils/log.h"

std::map<char, GLuint> digitTextures;

// std::vector<GLuint> digitTextures(NUM_DIGITS); // store texture ID for digits
//
// GLuint loadTextureRegion (const unsigned char *data, int x, int y, int width, int height, int totalWidth, int totalHeight, GLenum format) {
//
//   // Generate texture ID;
//   GLuint textureID;
//   glGenTextures(1, &textureID);
//
//   // Bind texture
//   glBindTexture(GL_TEXTURE_2D, textureID);
//
//   // Create and empty texture
//   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
//
//   // Copy the region from sprite sheet to texture
//   glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, width, height, format, GL_UNSIGNED_BYTE, data + (y * totalWidth + x) * (format == GL_RGBA ? 4 : 3));
//
//   // Set texture parameters
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//   return textureID;
//
// }

// GLuint loadTexture(const char *filePath) {
//     int width, height, nrChannels;
//     // stbi_set_flip_vertically_on_load(true);
//     unsigned char *data = stbi_load(filePath, &width, &height, &nrChannels, 0);
//     if (!data) {
//     std::cerr << "Failed to load texture: " << filePath << std::endl;
//         return 0;
//     }

//     GLuint texture;
//     glGenTextures(1, &texture);
//     glBindTexture(GL_TEXTURE_2D, texture);

//     GLenum format = nrChannels == 4 ? GL_RGBA : GL_RGB;

//     glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     stbi_image_free(data);

//     std::cout << "Loaded texture: " << filePath << " with ID: " << texture << std::endl;
//     return texture;
// }






// void loadDigitTextures(const char *filename) {
// stbi_set_flip_vertically_on_load(true);
//
//
//   // Load the spite sheet using stb_image
//   int width, height, nrChannels;
//   unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);
//   if (!data) {
//     std::cerr << "Failed to load spite sheet: " << filename << std::endl;
//     return;
//   }
//
//   // Determine the format based on number of nrChannels
//   GLenum format = nrChannels == 4 ? GL_RGBA : GL_RGB;
//
//   // ensure that spite shet has enough width and height
//   if (width < DIGIT_WIDTH * NUM_DIGITS || height < DIGIT_HEIGHT) {
//     std::cerr << "Spite sheet dimensions are too small." << std::endl;
//     stbi_image_free(data);
//     return;
//   }
//
//   // Load each digit textre from sprite sheet
//   for (int i = 0; i < NUM_DIGITS; i++) {
//     int x = i * DIGIT_WIDTH;
//     int y = 0;
//     digitTextures[i] = loadTextureRegion(data, x, y, DIGIT_WIDTH, DIGIT_HEIGHT, width, height, format);
//   }
//
//   // Free image data
//   stbi_image_free(data);
//
// }


// void loadDigitTextures() {
//     for (char digit = '0'; digit <= '7'; ++digit) {
//         std::string filePath = pluginDirectory + "resources/fonts/GTX327/" + digit + ".png";
//             logFunc(filePath);
//         digitTextures[digit] = loadTexture(filePath.c_str());
//         if (digitTextures[digit] == 0) {
//         std::cerr << "Error loading texture for digit: " << digit << std::endl;
//         }
//     }
// }


GLuint loadSingleTexture(const char* filename) {

stbi_set_flip_vertically_on_load(true);

  // Load image using stb_image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (!data) {
        logMsg("Failed to load texture");
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return 0;  // Return 0 to indicate failure
    }

    // Generate texture ID
    GLuint textureID;
    glGenTextures(1, &textureID);

    // Bind texture
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Upload image data to GPU
    GLenum format = nrChannels == 4 ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Free image data
    stbi_image_free(data);

    return textureID;
}


GLuint intro_texture = 0;


// void load_gtx_intro() {
//   std::string filename = pluginDirectory + "resources/fonts/GTX327/LOAD_SCREEN.PNG";
//   logFunc("Loading intro screen: " + filename);
//   intro_texture = loadSingleTexture(filename.c_str());
// }


// GLuint bezel_texture = 0;
// void load_gtx_bezel() {
//   std::string filename = pluginDirectory + "resources/images/avionics/gtx327_bezel.png";
//   logFunc("Loading Bezel: " + filename);
//   bezel_texture = loadSingleTexture(filename.c_str());


// }
