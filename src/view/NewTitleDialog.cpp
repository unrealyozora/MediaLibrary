#include "NewTitleDialog.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPushButton>
NewTitleDialog::NewTitleDialog(QLabel* oldTitle, QWidget* parent):QDialog(parent), originalTitle(oldTitle) {
	setWindowTitle("Change title");
	QVBoxLayout* layout = new QVBoxLayout(this);
	layout->addWidget(&titleEdit);
	buttonBox = new QDialogButtonBox(
		QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	QObject::connect(buttonBox, &QDialogButtonBox::accepted, this, &NewTitleDialog::onAccepted);
	QObject::connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
	connect(&titleEdit, &QLineEdit::textChanged, this, &NewTitleDialog::onTextChanged);
	layout->addWidget(buttonBox);
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

void NewTitleDialog::onAccepted(){
	originalTitle->setText(titleEdit.text());
	accept();
}

void NewTitleDialog::onTextChanged(const QString& text){
	buttonBox->button(QDialogButtonBox::Ok)->setEnabled(!text.isEmpty());
}
