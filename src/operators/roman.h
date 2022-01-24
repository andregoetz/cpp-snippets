#ifndef __ROMAN_H__
#define __ROMAN_H__

#include <string>
#include <ostream>
#include <optional>

class RomanNumber {
   friend std::ostream& operator<<(std::ostream& o, const RomanNumber& rn);
  /** Zahlwert für den diese Römische Zahl steht */
  std::uint32_t value;
protected:
  /**
   * Liefert einen string, der die Römische Zahl als Zeichenkette
   * repräsentiert (zum internen Gebrauch) */
  const std::string getStringRep() const;
public:
  /*---- Konstruktoren / Destruktor ------------------------------------------*/
  /**
   * Initialisierung einer Römischen Zahl aus einem String.
   * Für ungültige `string` wird eine `string`-Exception geworfen;
   * der leere `string` ist nicht erlaubt.
   *
   * ACHTUNG! Konvertierungskonstruktor
   **/
  RomanNumber(const std::string& rstr);
  /**
   * Initialisierung einer Römischen Zahl aus einem uint32_t.
   * Die Zahl 0 ist nicht erlaubt und führt zu einer `string`-exception.
   *
   * ACHTUNG! Konvertierungskonstruktor
   **/
  RomanNumber(uint32_t rval);

  // Einiges darf der Compiler wieder für uns erledigen ....

  RomanNumber(const RomanNumber& rhs) = default;
  ~RomanNumber() = default;

  /*---- Konvertierungsoperatoren --------------------------------------------*/
  /**
   * Erlaubt die explizite Konvertierung einer Römischen
   * Zahl in einen uint32_t
   **/
  explicit operator uint32_t() const {
    return value;
  }

  /**
   * Die Länge der Zahl in Zeichen */
  size_t length() const {
    return getStringRep().length();
  }

  /*---- Member-Only Operatoren ----------------------------------------------*/
  RomanNumber& operator=(const RomanNumber& rhs) = default;

  /**
   * Ungesicherter Zugriff auf die einzelnen Ziffern. */
  char operator[](size_t idx) const noexcept;
  /**
   * Ungesicherter Zugriff auf die einzelnen Ziffern mit
   * Römischem Index.
   *
   * ACHTUNG! Indexbereich ist 1..length !!
   * */
  char operator[](const RomanNumber& ridx) const noexcept;

  /**
   * Gesicherter Zugriff auf die einzelnen Ziffern */
  char operator()(size_t idx) const noexcept(false);

  /**
   * Liefert einen Substring der Zahl. Hier nur zur Demonstration,
   * dass operator() mehrfach überladen werden kann. */
  std::string operator()(size_t start, size_t len) const;

  /*---- Arithmetische Zuweisungsoperatoren als Methode (EMPFOHLEN!) ---------*/
  RomanNumber& operator+=(const RomanNumber& val);
  RomanNumber& operator-=(const RomanNumber& val);


  /*---- Arithmetische Zuweisungsoperatoren als Funktion ---------------------*/
  // Beachte: erstes Argument muss non-const sein, da es ja geändert wird!
  friend RomanNumber& operator*=(RomanNumber& op1, const RomanNumber& op2);
  friend RomanNumber& operator/=(RomanNumber& op1, const RomanNumber& op2);

  /*---- Binäre arithmetische Operatoren als Funktionen (EMPFOHLEN!) --------*/
  friend RomanNumber operator+(const RomanNumber& lhs,const RomanNumber& rhs);
  friend RomanNumber operator-(const RomanNumber& lhs,const RomanNumber& rhs);
  friend RomanNumber operator*(const RomanNumber& lhs,const RomanNumber& rhs);
  friend RomanNumber operator/(const RomanNumber& lhs,const RomanNumber& rhs);


  /*--- Binäre Vergleichsoperatoren ------------------------------------------*/
  friend bool operator==(const RomanNumber& lhs,const RomanNumber& rhs);
  friend bool operator!=(const RomanNumber& lhs,const RomanNumber& rhs);
  friend bool operator<=(const RomanNumber& lhs,const RomanNumber& rhs);
  friend bool operator>=(const RomanNumber& lhs,const RomanNumber& rhs);

  /*---- Increment / Decrement als Methode (EMPFOHLEN!) ----------------------*/
  RomanNumber& operator++();   // Präfix
  RomanNumber operator++(int); // Postfix

  /*---- Increment / Decrement als Funktion (NICHT EMPFOHLEN!) ---------------*/
  friend RomanNumber& operator--(RomanNumber& rn);
  friend RomanNumber operator--(RomanNumber& rn,int);

  /*---- Vorzeichen + als Methode --------------------------------------------*/
  RomanNumber operator+() const;

  /*--- Vorzeichen - als Funktion --------------------------------------------*/
  friend RomanNumber operator-(const RomanNumber&);
};

/**
 * Ausgabe einer Römischen Zahl in einen Stream */
std::ostream& operator<<(std::ostream& o, const RomanNumber& rn);

#endif
