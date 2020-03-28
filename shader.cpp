#include "shader.h"
#include <QDebug>

Shader::Shader(const QString& vertex_shader_path, const QString& fragment_shader_path) {
    bool success;

    QOpenGLShader vertex_shader(QOpenGLShader::Vertex);
    success = vertex_shader.compileSourceFile(vertex_shader_path);
    if (!success) {
        qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED" << endl;
        qDebug() << vertex_shader.log() << endl;
    }

    QOpenGLShader fragment_shader(QOpenGLShader::Fragment);
    success = fragment_shader.compileSourceFile(fragment_shader_path);
    if (!success) {
        qDebug() << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED" << endl;
        qDebug() << fragment_shader.log() << endl;
    }

    shader.addShader(&vertex_shader);
    shader.addShader(&fragment_shader);
    success = shader.link();
    if (!success) {
        qDebug() << "ERROR: shader program fail, " << endl;
        qDebug() << shader.log() << endl;
    }
}

void Shader::use() {
    shader.bind();
}


void Shader::setUniformBool(const QString& name, const bool& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformInt(const QString& name, const int& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformFloat(const QString& name, const float& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformVec2(const QString& name, const QVector2D& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformVec3(const QString& name, const QVector3D& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformVec4(const QString& name, const QVector4D& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformMat2(const QString& name, const QMatrix2x2& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformMat3(const QString& name, const QMatrix3x3& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

void Shader::setUniformMat4(const QString& name, const QMatrix4x4& value) {
    shader.setUniformValue(shader.uniformLocation(name), value);
}

Shader::~Shader() {

}
