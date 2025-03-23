#include "LengthEdit.h"

LengthEdit::LengthEdit(QWidget* parent, unsigned int initialminutes):QLineEdit(parent){
	setValidator(new QIntValidator(0, 3000, this));
	setMinutes(initialminutes);
	connect(this, &QLineEdit::textChanged, this, &LengthEdit::textChanged);
	
}

void LengthEdit::setMinutes(unsigned int minutes) {
	QString text = QString::number(minutes) + " Minuti";
	setText(QString::number(minutes) + " Minuti");
}

int LengthEdit::minutes() const{
	QString text = this->text();
	bool ok;
	int value = text.split(" ").first().toInt(&ok);
	return ok ? value : 0;
}

void LengthEdit::focusInEvent(QFocusEvent* event){
	QLineEdit::focusInEvent(event);
	QString text = this->text();
	setText(text.split(" ").first());
}

void LengthEdit::focusOutEvent(QFocusEvent* event){
	QLineEdit::focusOutEvent(event);
	QString text = this->text();
	setText(text + " Minuti");
}

void LengthEdit::textChanged(const QString& text) {
	bool ok;
	text.toInt(&ok);
	if (!ok) {
		setText(text.split(" ").first());
	}
}
