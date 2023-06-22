
#include "calibraiontests.h"

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

QList<QString> CalibrationPictures{":/material/photos/LCD.png",
                                   ":/material/photos/Scope.png",
                                   ":/material/photos/Brightness.png"};

CalibraionTests::CalibraionTests(bool isAutoTest, size_t delay, QWidget *parent)
    : QWidget{parent}
    , m_IsAutoTest{isAutoTest}
    , m_Delay{delay}
    , picture{nullptr}
    , m_TestType{NONE_TEST}
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
        connect(timer, &QTimer::timeout, this, &CalibraionTests::SimulateRightArrowKey);
        timer->start(m_Delay * 1000);
    }
}

CalibraionTests::~CalibraionTests()
{
    if (backButton != nullptr)
        delete backButton;
    if (timer != nullptr)
        delete timer;
    if (picture != nullptr)
        delete picture;
}

void CalibraionTests::SimulateRightArrowKey()
{
    QKeyEvent *event = new QKeyEvent(QKeyEvent::KeyPress, Qt::Key_Right, Qt::NoModifier);
    keyPressEvent(event);
    delete event;
}

void CalibraionTests::MakeTest(int indexOfList)
{
    m_TestType = (CalibraionTestTypes) m_CalibraionCodeList[indexOfList];
    if (m_TestType == NONE_TEST)
        return;
    picture = new QLabel(this);
    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    QSize screenSize = screenGeometry.size();
    QPixmap pixmap(CalibrationPictures[m_TestType]);
    picture->setPixmap(pixmap.scaled(screenSize));
    picture->setGeometry(QRect(QPoint(0, 0), screenSize));
    picture->showFullScreen();
    backButton->raise();
}

void CalibraionTests::keyPressEvent(QKeyEvent *event)
{
    if (picture != nullptr) {
        delete picture;
        picture = nullptr;
    }
    switch (event->key()) {
    case Qt::Key_Left:
        m_TestIndex = (m_TestIndex - 1 + m_CalibraionCodeList.size()) % m_CalibraionCodeList.size();
        MakeTest(m_TestIndex);
        break;
    case Qt::Key_Right:
        m_TestIndex = (m_TestIndex + 1) % m_CalibraionCodeList.size();
        MakeTest(m_TestIndex);
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}
