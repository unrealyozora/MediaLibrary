#ifndef VIEW_LENGTH_EDIT_H
#define VIEW_LENGTH_EDIT_H
#include <QLineEdit>
#include <QIntValidator>

class LengthEdit : public QLineEdit {
	Q_OBJECT
private slots:
	void textChanged(const QString& text);
public slots:
	void undo() override;
private:
	int savedMinutes;
public:
	LengthEdit(QWidget* parent = nullptr, unsigned int initialminutes=0);
	void setMinutes(unsigned int minutes);
	int minutes() const;
protected:
	void focusInEvent(QFocusEvent* event) override;
	void focusOutEvent(QFocusEvent* event) override;

	
};
#endif
