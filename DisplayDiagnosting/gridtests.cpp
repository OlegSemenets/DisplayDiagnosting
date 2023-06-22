
#include "gridtests.h"

#include <QGuiApplication>
#include <QKeyEvent>
#include <QLinearGradient>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QPushButton>
#include <QRect>
#include <QScreen>
#include <QTimer>
#include <QVBoxLayout>
#include <QtWidgets>

GridTests::GridTests(bool isAutoTest, size_t delay, QColor background, QWidget *parent)
    : QWidget{parent}
    , m_IsAutoTest{isAutoTest}
    , m_Delay{delay}
    , m_BackGroundColor{background}
    , picture{nullptr}
{
    backButton = new QPushButton("X", this);
    backButton->setStyleSheet("background-color: red;");
    backButton->setGeometry(
        QRect(QPoint(QGuiApplication::primaryScreen()->geometry().width() - 35, 5), QSize(30, 30)));
    connect(backButton, &QPushButton::clicked, this, &QWidget::close);

    m_TestIndex = 0;
    setFocusPolicy(Qt::StrongFocus);

    if (m_IsAutoTest) {
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &GridTests::SimulateRightArrowKey);
        timer->start(m_Delay * 1000);
    }
}

GridTests::~GridTests()
{
    if (backButton != nullptr)
        delete backButton;
    if (timer != nullptr)
        delete timer;
    if (picture != nullptr)
        delete picture;
}

void GridTests::SimulateRightArrowKey()
{
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    keyPressEvent(event);
    delete event;
}

void GridTests::createGridImage(QColor gridColor)
{
    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath = executablePath + "/gridImage.png";

    QScreen *screen = QGuiApplication::primaryScreen();
    const int cell_size = screen->geometry().width() / 20;
    const int cell_size2 = screen->geometry().height() / 20;
    const int rows = 20;
    const int cols = 20;
    const int grid_width = cell_size * cols;
    const int grid_height = cell_size2 * rows;
    const int x_offset = (screen->geometry().width() - grid_width) / 2;
    const int y_offset = (screen->geometry().height() - grid_height) / 2;

    QImage gridImage(screen->geometry().size(), QImage::Format_RGB32);
    gridImage.fill(m_BackGroundColor);

    QPainter painter(&gridImage);
    painter.setPen(QPen(gridColor, 1, Qt::SolidLine));

    for (int i = 0; i <= cols; i++) {
        const int x = x_offset + i * cell_size;
        painter.drawLine(x, y_offset, x, y_offset + grid_height);
    }

    for (int i = 0; i <= rows; i++) {
        const int y = y_offset + i * cell_size2;
        painter.drawLine(x_offset, y, x_offset + grid_width, y);
    }

    gridImage.save(filePath);
}

void GridTests::MakeTest(int indexOfList)
{
    QString executablePath = QCoreApplication::applicationDirPath();
    QString filePath = executablePath + "/gridImage.png";

    createGridImage(m_GridColorList[indexOfList]);
    picture = new QLabel(this);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    QSize screenSize = screenGeometry.size();
    QPixmap pixmap(filePath);
    picture->setPixmap(pixmap.scaled(screenSize));
    picture->setGeometry(QRect(QPoint(0, 0), screenSize));
    picture->showFullScreen();
    backButton->raise();
}

void GridTests::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        m_TestIndex = (m_TestIndex - 1 + m_GridColorList.size()) % m_GridColorList.size();
        MakeTest(m_TestIndex);
        break;
    case Qt::Key_Right:
        m_TestIndex = (m_TestIndex + 1) % m_GridColorList.size();
        MakeTest(m_TestIndex);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
