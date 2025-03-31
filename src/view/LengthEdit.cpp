#include "LengthEdit.h"

LengthEdit::LengthEdit(QWidget* parent, unsigned int initialminutes)
	: QLineEdit(parent), savedMinutes(initialminutes), lastValidMinutes(initialminutes) {

	setValidator(new QIntValidator(0, 3000, this)); // Imposta un validatore tra 0 e 3000
	setMinutes(initialminutes);

	// Connetti il segnale textChanged per tenere traccia delle modifiche
	connect(this, &QLineEdit::textChanged, this, &LengthEdit::textChanged);
}

void LengthEdit::setMinutes(unsigned int minutes) {
	savedMinutes = minutes;
	lastValidMinutes = minutes;
	setText(QString::number(minutes) + " Minuti");
}

int LengthEdit::minutes() const {
	bool ok;
	int value = text().split(" ").first().toInt(&ok);
	return ok ? value : savedMinutes;  // Se il parsing fallisce, restituisce il valore salvato
}

void LengthEdit::focusInEvent(QFocusEvent* event) {
	QLineEdit::focusInEvent(event);
	setText(QString::number(lastValidMinutes)); // Rimuove "Minuti" quando il campo è attivo
}

void LengthEdit::focusOutEvent(QFocusEvent* event) {
	QLineEdit::focusOutEvent(event);
	bool ok;
	int value = text().split(" ").first().toInt(&ok);

	if (ok && value >= 0 && value <= 3000) {
		lastValidMinutes = value;  // Memorizza il nuovo valore valido
		setText(QString::number(value) + " Minuti");
	}
	else {
		// Se il valore inserito è fuori limite o non valido, ripristina l'ultimo valido
		setText(QString::number(lastValidMinutes) + " Minuti");
	}
}

void LengthEdit::textChanged(const QString& text) {
	bool ok;
	int value = text.split(" ").first().toInt(&ok);

	// Aggiorna l'ultimo valore valido solo se l'input è corretto
	if (ok && value >= 0 && value <= 3000) {
		lastValidMinutes = value;
	}
}

void LengthEdit::undo() {
	lastValidMinutes = savedMinutes;  // Ripristina il valore originale
	setText(QString::number(savedMinutes) + " Minuti");
}
