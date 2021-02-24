#pragma once

#include <string>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/transform.hpp>

#include "config.hpp"

using namespace std;

namespace MathUtils {
    struct Rect {
        GLfloat x0;
        GLfloat y0;
        GLfloat x1;
        GLfloat y1;

        Rect(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1) {
            this->x0 = x0;
            this->x1 = x1;
            this->y0 = y0;
            this->y1 = y1;
        }

        string toString() {
            int a = 2;
            stringstream stream;
            stream << "(" << this->x0 << ", " << this->y0 << "), (" << this->x1 << ", " << this->y1 << ")";
            return stream.str();
        }
    };

    bool areRectsIntercepting(Rect* r1, Rect* r2) {
        return (
            r1->x0 < r2->x1 && r1->x1 > r2->x0 &&
            r1->y1 > r2->y0 && r1->y0 < r2->y1
        );
    }

    const glm::mat4 projectionMatrix =
        glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(1, 0, 0)) *
        glm::translate(glm::vec3(-1.0, -1.0, 0.0)) *
        glm::scale(glm::vec3(2.0 / WINDOW_WIDTH, 2.0 / WINDOW_HEIGHT, 1.f));
}