#ifndef PLAYERCONTROLS_H
#define PLAYERCONTROLS_H

#include <QMediaPlayer>
#include <QWidget>

QT_BEGIN_NAMESPACE
class QAbstractButton;//按钮抽象基类
class QAbstractSlider;//进度条抽象基类
class QComboBox;/*下拉列表，每个列表项可以关联一个QVariant类型的变量，
                                       用于储存一些不可见的数据*/
QT_END_NAMESPACE

class PlayerControls : public QWidget
{
    Q_OBJECT

public:
    PlayerControls(QWidget *parent = 0);

    QMediaPlayer::State state() const;//定义媒体播放器当前的状态
    int volume() const;
    bool isMuted() const;//是否静音
    qreal playbackRate() const;//播放速度

public slots:/*槽函数*/
    void setState(QMediaPlayer::State state);//设置状态函数
    void setVolume(int volume);//设置音量函数
    void setMuted(bool muted);//设置静音函数

signals:/*信号*/
    void play();//播放
    void pause();//暂停
    void stop();//停止
    void next();//下一首
    void previous();//上一首
    void changeVolume(int volume);//调整音量
    void changeMuting(bool muting);//改变静音状态
    void changeRate(qreal rate);//改变速度

private slots:
    void playClicked();//点击播放
    void muteClicked();//点击静音

private:
    QMediaPlayer::State playerState;
    bool playerMuted;
    QAbstractButton *playButton;//设置播放按钮
    QAbstractButton *stopButton;//设置停止按钮
    QAbstractButton *nextButton;//设置下一首按钮
    QAbstractButton *previousButton;//设置上一首按钮
    QAbstractButton *muteButton;//设置静音按钮
    QAbstractSlider *volumeSlider;//设置音量条
};

#endif // PLAYERCONTROLS_H
