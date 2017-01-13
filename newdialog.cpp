#include "newdialog.h"

#include <QGridLayout>
#include <QLabel>

NewDialog::NewDialog(QWidget * parent) :
        QDialog(parent)
{
        mVerticesSpinBox = new QSpinBox();
        mVerticesSpinBox->setMinimum(2);
        mVerticesSpinBox->setMaximum(10000);
        mJumpSpinBox = new QSpinBox();
        mJumpSpinBox->setMinimum(0);
        mJumpSpinBox->setMaximum(10000);
        mChanceSpinBox = new QDoubleSpinBox();
        mChanceSpinBox->setMinimum(0.0);
        mChanceSpinBox->setMaximum(1.0);
        mOkButton = new QPushButton("OK");

        QGridLayout * layout = new QGridLayout(this);
        layout->addWidget(new QLabel("Number of vertices"), 0, 0);
        layout->addWidget(mVerticesSpinBox, 0, 1);
        layout->addWidget(new QLabel("Maximum \"edge length\""), 1, 0);
        layout->addWidget(mJumpSpinBox, 1, 1);
        layout->addWidget(new QLabel("Edge occurence probability"), 2, 0);
        layout->addWidget(mChanceSpinBox, 2, 1);
        layout->addWidget(mOkButton, 3, 0, 1, 2);

        connect(mOkButton, SIGNAL(clicked(bool)), this, SLOT(accept()));
}

int NewDialog::vertices()
{
        return mVerticesSpinBox->value();
}

int NewDialog::jump()
{
        return mJumpSpinBox->value();
}

qreal NewDialog::chance()
{
        return mChanceSpinBox->value();
}
