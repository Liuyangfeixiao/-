#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QVideoWidget>

class VideoWidget : public QVideoWidget
{
    Q_OBJECT

public:
    VideoWidget(QWidget *parent = 0);

protected:/*添加动作*/
    void keyPressEvent(QKeyEvent *event);//按键盘
    void mouseDoubleClickEvent(QMouseEvent *event);//双击鼠标
    void mousePressEvent(QMouseEvent *event);//按鼠标
};

#endif // VIDEOWIDGET_H
