#pragma once
#include <glm/glm.hpp>
#include <memory>
#include <pybind11/numpy.h>

namespace glm {
typedef vec<3, int> vec3i;
typedef vec<3, float> vec3f;
}

namespace three {
namespace scene {
    namespace py = pybind11;
    class Object {
    private:
        void _update_model_matrix();

    public:
        std::unique_ptr<glm::vec3i[]> _faces;
        std::unique_ptr<glm::vec3f[]> _vertices;
        std::unique_ptr<glm::vec3f[]> _face_vertices;
        std::unique_ptr<glm::vec3f[]> _face_normal_vectors;
        std::unique_ptr<glm::vec3f[]> _face_vertex_normal_vectors;
        int _num_faces;
        int _num_vertices;
        glm::vec3 _position; // xyz
        glm::vec3 _rotation_rad; // xyz
        glm::vec4 _color; // RGBA
        glm::vec3 _scale; // xyz
        glm::mat4 _model_matrix;
        Object(const Object* source);
        Object(py::array_t<int> np_faces, py::array_t<float> np_vertices, py::tuple color, py::tuple scale);
        void set_color(py::tuple color);
        void set_scale(py::tuple scale);
        void set_position(py::tuple position);
        void set_rotation(py::tuple rotation_rad);
        std::shared_ptr<Object> clone();
    };
}
}