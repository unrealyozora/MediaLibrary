#ifndef VIEW_LENGTH_EDIT_H
#define VIEW_LENGTH_EDIT_H
#include <QLineEdit>
#include <QIntValidator>

class LengthEdit : public QLineEdit {
	Q_OBJECT
private slots:
	void textChanged(const QString& text);
public slots:
	void undo();
private:
	int savedValue;
	int lastValidValue;
	QString _text;
public:
	LengthEdit(const QString& text, QWidget* parent = nullptr, unsigned int initialminutes=0);
	void setValue(unsigned int minutes);
	unsigned int value() const;
protected:
	void focusInEvent(QFocusEvent* event) override;
	void focusOutEvent(QFocusEvent* event) override;

	
};
#endif
