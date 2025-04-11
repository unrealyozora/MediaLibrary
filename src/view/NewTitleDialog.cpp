#include "NewTitleDialog.h"
#include <QDialogButtonBox>
#include <QVBoxLayout>
NewTitleDialog::NewTitleDialog(QLabel* oldTitle, QWidget* parent):QDialog(parent), originalTitle(oldTitle) {
	setWindowTitle("Change title");
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(&titleEdit);
	QDialogButtonBox* buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	QObject::connect(buttonBox, &QDialogButtonBox::accepted, this, &NewTitleDialog::onAccepted);
	QObject::connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	layout->addWidget(buttonBox);
}

void NewTitleDialog::onAccepted(){
	originalTitle->setText(titleEdit.text());
	accept();
}
