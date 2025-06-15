#include "LengthEdit.h"
LengthEdit::LengthEdit(const QString& text, QWidget* parent, unsigned int initialValue)
	: QLineEdit(parent), savedValue(initialValue), lastValidValue(initialValue), _text(text)  {

	setValidator(new QIntValidator(0, 3000, this)); // Imposta un validatore tra 0 e 3000
	setValue(initialValue);

	// Connetti il segnale textChanged per tenere traccia delle modifiche
	connect(this, &QLineEdit::textChanged, this, &LengthEdit::textChanged);
}

void LengthEdit::setValue(unsigned int value) {
	savedValue = value;
	lastValidValue = value;
	setText(QString::number(value) +" " +  _text);
}

unsigned int LengthEdit::value() const {
	bool ok;
	unsigned int value = text().split(" ").first().toUInt(&ok);
	return ok ? value : savedValue;  // Se il parsing fallisce, restituisce il valore salvato
}

void LengthEdit::focusInEvent(QFocusEvent* event) {
	QLineEdit::focusInEvent(event);
	setText(QString::number(lastValidValue)); // Rimuove "Minuti" quando il campo è attivo
}

void LengthEdit::focusOutEvent(QFocusEvent* event) {
	QLineEdit::focusOutEvent(event);
	bool ok;
	int value = text().split(" ").first().toInt(&ok);

	if (ok && value >= 0 && value <= 3000) {
		lastValidValue = value;  // Memorizza il nuovo valore valido
		setText(QString::number(value) +" " +  _text);
	}
	else {
		// Se il valore inserito è fuori limite o non valido, ripristina l'ultimo valido
		setText(QString::number(lastValidValue) + _text);
	}
}

void LengthEdit::textChanged(const QString& text) {
	bool ok;
	unsigned int value = text.split(" ").first().toInt(&ok);

	// Aggiorna l'ultimo valore valido solo se l'input è corretto
	if (ok && value <= 3000) {
		lastValidValue = value;
	}
}

void LengthEdit::undo() {
	lastValidValue = savedValue;  // Ripristina il valore originale
	setText(QString::number(savedValue) + " " + _text);
}
