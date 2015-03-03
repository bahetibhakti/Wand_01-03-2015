#ifndef CAMERAWINDOW_H_
#define CAMERAWINDOW_H_

#include <QWidget>
#include <QVBoxLayout>
#include <qgridlayout.h>
#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include "camerawidget.h"
#include <QGroupBox>
#include <QTimer>

class CameraWindow : public QWidget
{
    Q_OBJECT
public:
    CameraWindow(CvCapture *camera, QWidget *parent=0);

private:
    CameraWidget *m_cvwidget;
    CvCapture *m_camera;
    int m_photoCounter;
    QLabel *m_window ;
    QWidget* m_widget ;
    int m_count ;
    QTimer *timer;


protected:
    void timerEvent(QTimerEvent*);
    void createHorizontalGroupBox();
    QGroupBox *horizontalGroupBox;

public slots:
    void flowImg(void);
    void savePicture(void);
    void directImg(void);
    void restart(void);
    void capturePicture(void) ;

};

#endif
