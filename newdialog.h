#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

#include <QDoubleSpinBox>
#include <QPushButton>
#include <QSpinBox>

class NewDialog : public QDialog
{
                Q_OBJECT
        public:
                NewDialog(QWidget * parent = 0);
                int vertices();
                int jump();
                qreal chance();
        private:
                QSpinBox * mVerticesSpinBox;
                QSpinBox * mJumpSpinBox;
                QDoubleSpinBox * mChanceSpinBox;
                QPushButton * mOkButton;
};

#endif // NEWDIALOG_H
