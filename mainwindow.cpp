#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QSound>

float speedSelect(int idx) {
    return 0.5f * (idx + 1);
}

int sizeSelect(int idx) {
    return 1 << (idx + 3);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setFixedSize(1280, 720);
    setWindowIcon(QIcon(":/img/snake_icon.png"));
    setWindowTitle("贪吃蛇大战 v1.0");

    QSound* bg_sound = new QSound(":/audio/bg.wav");
    bg_sound->setLoops(QSound::Infinite);

    connect(ui->start_btn, &QPushButton::clicked, this, [=]() {
        Game* game = new Game(this, sizeSelect(ui->size_comboBox->currentIndex()), speedSelect(ui->speed_comboBox->currentIndex()));
        game->setFocus();
        game->show();
        bg_sound->play();

        connect(game, &Game::quitGame, this, [=]() {
            bg_sound->stop();
            emit this->deleteGame();
        });

        connect(this, &MainWindow::deleteGame, game, &QOpenGLWidget::close);
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/img/snake_bg.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}
