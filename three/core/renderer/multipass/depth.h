#pragma once
#include <gl3w/gl3w.h>

namespace three {
namespace renderer {
    namespace multipass {
        class Depth {
        private:
            GLuint _program;
            GLuint _uniform_projection_mat;
            GLuint _uniform_model_mat;
            GLuint _uniform_view_mat;

        public:
            Depth();
            void use();
        };
    }
}
}