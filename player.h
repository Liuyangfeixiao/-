#ifndef PLAYER_H
#define PLAYER_H

#include "videowidget.h"

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

QT_BEGIN_NAMESPACE
class QAbstractItemView;//提供视图类基本功能
class QLabel;//提供文本或图像显示
class QMediaPlayer;
class QModelIndex;//定位数据模型中的数据
class QPushButton;//提供按钮
class QSlider;//提供进度条
class QVideoProbe;//允许监视正在播放或录制的视频
class QVideoWidget;//呈现视频
QT_END_NAMESPACE

class PlaylistModel;//创建列表类
class HistogramWidget;//历史纪录

class Player : public QWidget/*主窗口类的构造*/
{
    Q_OBJECT

public:
    Player(QWidget *parent = 0);
    ~Player();

signals:
    void fullScreenChanged(bool fullScreen);//全屏显示

private slots:
    void open();//打开文件
    void durationChanged(qint64 duration);//持续时间改变,在切换文件时发出
    void positionChanged(qint64 progress);//位置改变
    void metaDataChanged();//数据改变

    void previousClicked();//

    void seek(int seconds);
    void jump(const QModelIndex &index);//目录跳转
    void playlistPositionChanged(int);

    void statusChanged(QMediaPlayer::MediaStatus status);//定义播放器当前缓冲状态
    void bufferingProgress(int progress);//缓冲过程
    void videoAvailableChanged(bool available);//视频状态

    void displayErrorMessage();//播放出错

    void addToPlaylist(const QStringList &fileNames);//将视频加入列表

private:
    void setTrackInfo(const QString &info);//跟踪信息
    void setStatusInfo(const QString &info);//缓存信息
    void handleCursor(QMediaPlayer::MediaStatus status);//处理光标移动
    void updateDurationInfo(qint64 currentInfo);//更新持续时间
/*声明数据*/
    QMediaPlayer *player;
    QMediaPlaylist *playlist;
    VideoWidget *videoWidget;
    QLabel *coverLabel;
    QSlider *slider;
    QLabel *labelDuration;
    QPushButton *fullScreenButton;

    PlaylistModel *playlistModel;
    QAbstractItemView *playlistView;
    QString trackInfo;
    QString statusInfo;
    qint64 duration;
};

#endif // PLAYER_H
