
#include "gradienttests.h"

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

GradientTests::GradientTests(bool isAutoTest, size_t delay, QWidget *parent)
    : QWidget{parent}
    , m_IsAutoTest{isAutoTest}
    , m_Delay{delay}
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
        connect(timer, &QTimer::timeout, this, &GradientTests::SimulateRightArrowKey);
        timer->start(m_Delay * 1000);
    }
}

GradientTests::~GradientTests()
{
    if (backButton != nullptr)
        delete backButton;
    if (timer != nullptr)
        delete timer;
}

void GradientTests::MakeTest(int indexOfList)
{
    setStyleSheet("QWidget {"
                  "background-color: palette(Window);"
                  "color: palette(WindowText);"
                  "}");
    QPalette standartPalette = QApplication::palette();
    setPalette(standartPalette);
    QLinearGradient gradient_fill(0,
                                  0,
                                  QGuiApplication::primaryScreen()->geometry().width(),
                                  QGuiApplication::primaryScreen()->geometry().height());
    gradient_fill.setColorAt(0, QColor(0, 0, 0, 0));
    gradient_fill.setColorAt(1, m_GradientList[indexOfList]);
    setAutoFillBackground(false);
    QPalette paletteToFill = palette();
    paletteToFill.setBrush(QPalette::Window, QBrush(gradient_fill));
    setPalette(paletteToFill);
}

void GradientTests::SimulateRightArrowKey()
{
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    keyPressEvent(event);
    delete event;
}

void GradientTests::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Left:
        m_TestIndex = (m_TestIndex - 1 + m_GradientList.size()) % m_GradientList.size();
        MakeTest(m_TestIndex);
        break;
    case Qt::Key_Right:
        m_TestIndex = (m_TestIndex + 1) % m_GradientList.size();
        MakeTest(m_TestIndex);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
