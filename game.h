#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H
#include <QTime>
#include <vector>
#include <QKeyEvent>
#include <QVector2D>
#include <QVector3D>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <QOpenGLFunctions>
#include <QOpenGLFunctions_4_5_Core>
#include "shader.h"
#include "player.h"

class Game : public QOpenGLWidget {
    Q_OBJECT
public:
    Game(QWidget* parent, int _x_tile_count = 32, float _speed = 8.0f);
    ~Game();

signals:
    void quitGame();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    bool status;
    bool first;

    unsigned int vao;
    int x_tile_count;
    int y_tile_count;
    float tile_width;
    float tile_height;
    float speed;

    std::vector<QVector2D> empty_tile;

    QVector3D* food;

    Player* red_player;
    Player* blue_player;

    QTime* time;
    float last_update;

    Shader* shader;
    QOpenGLTexture* tile_texture;
    QOpenGLTexture* head_texture;
    QOpenGLFunctions_4_5_Core* core;

    void generateFood();
    void drawBackground();
    void drawSnake();
    void drawTile(QVector2D pos, QVector4D color, bool head = false);
    void drawFood();
    void drawScore();
    bool removeFromEmptyTile(QVector2D val);
    void updateGame();
};

#endif // GAMEWINDOW_H
