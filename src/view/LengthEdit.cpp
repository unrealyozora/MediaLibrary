#include "LengthEdit.h"

LengthEdit::LengthEdit(QWidget* parent, unsigned int initialminutes):QLineEdit(parent){
	setValidator(new QIntValidator(0, 3000, this));
	setMinutes(initialminutes);
	connect(this, &QLineEdit::textChanged, this, &LengthEdit::textChanged);
	
}

void LengthEdit::setMinutes(unsigned int minutes) {
	savedMinutes=minutes;
	QString text = QString::number(minutes) + " Minuti";
	setText(text);
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
	bool ok;
	int value = text.split(" ").first().toInt(&ok);
    if (ok && value >= 0 && value <= 3000) {
		savedMinutes=value;
        setText(QString::number(value) + " Minuti");  // Aggiungi "Minuti" solo se il valore è valido
    }else {
		// Se il numero non è valido, rimuovi " Minuti" per non avere un formato errato
        setText(QString::number(savedMinutes) + " Minuti"); // Per esempio, metti 0 se il numero è fuori dal range
	}
}

void LengthEdit::textChanged(const QString& text) {
	bool ok;
	int value = text.split(" ").first().toInt(&ok);
	if (!ok || value < 0 || value > 3000) {  // Valida il numero dei minuti
		// Se il testo non è valido, ripristina il testo precedente
        setText(text.split(" ").first());
    }
}

void LengthEdit::undo() {
    QLineEdit::undo();  // Chiama il comportamento standard
    setText(QString::number(savedMinutes) + " Minuti");  // Ripristina il formato
}