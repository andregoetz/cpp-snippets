#include "roman.h"
#include <string>
#include <map>
using namespace std;


string int2Roman(uint32_t n) {
  string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  uint32_t values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

  string result = "";
  for (int i = 0; i < 13; ++i) {
    while(n >= values[i] ) {
      result += str_romans[i];
      n -= values[i];
    }
  }
  return result;
}

uint32_t Roman2int(const string& rstr) {
  size_t n = rstr.length();
  if (0 == n) {
      throw "Roman2int: leerer String ist nicht erlaubt!"s;
  }

  uint32_t result = 0;
  for (size_t i = 0; i < n; i++) {
    switch (rstr[i]) {
        case 'I':
          result += 1;
          break;
        case 'V':
          if ((i>0) && (rstr[i-1]=='I')) {
            result += -1 + 4;
          } else {
            result += 5;
          }
          break;
        case 'X':
          if ((i>0) && (rstr[i-1]=='I')) {
            result += -1 + 9;
          } else {
            result += 10;
          }
          break;
        case 'L':
          if ((i>0) && (rstr[i-1] == 'X')) {
            result += -10 + 40;
          } else {
            result += 50;
          }
          break;
        case 'C':
          if ((i>0) && (rstr[i-1] == 'X')) {
            result += -10 + 90;
          } else {
            result += 100;
          }
          break;
        case 'D':
          if ((i>0) && (rstr[i-1] == 'C')) {
            result += -100 + 400;
          } else {
            result += 500;
          }
          break;
        case 'M':
          if (i>0 && rstr[i-1] == 'C') {
            result += -100 + 900;
          } else {
            result += 1000;
          }
          break;
        default:
          throw "Unerlaubtes Zeichen"s;
    }
  }

  return result;
}

RomanNumber::RomanNumber(const string& rstr) {
  value = Roman2int(rstr);
}

RomanNumber::RomanNumber(uint32_t rval) : value(rval) {
  if (rval == 0) {
    throw "Die Null war den Römern nicht bekannt!"s;
  }
}

// Diese Umsetzung ist nicht sonderlich effizient, denn bei jedem Zugriff
// wird der string neu berechnet. Sinnvoller wäre die Umsetzung eines
// Caches, aber das wollen wir hier nicht weiter verfolgen ...


const std::string RomanNumber::getStringRep() const {
  return int2Roman(value);
}

ostream& operator<<(ostream& o, const RomanNumber& rn) {
  return o << rn.getStringRep();
}

char RomanNumber::operator[](size_t idx) const noexcept {
#ifdef __DEBUG__
  cout << "<-- operator[](size_t) mit " << idx << " -->" << flush;
#endif
  return getStringRep()[idx];
}

char RomanNumber::operator[](const RomanNumber& ridx) const noexcept {
#ifdef __DEBUG__
  cout << "<-- operator[](const RomanNumber&) mit " << ridx << " -->"  << flush;
#endif
  return getStringRep()[ridx.value + 1];
}

char RomanNumber::operator()(size_t idx) const noexcept(false) {
  if (idx>=length()) {
    throw "Indexfehler!"s;
  }
  return getStringRep()[idx];
}

string RomanNumber::operator()(size_t start, size_t len) const {
  return getStringRep().substr(start, len);
}

RomanNumber& RomanNumber::operator+=(const RomanNumber& other) {
  value += other.value;
  return *this;
}

RomanNumber& RomanNumber::operator-=(const RomanNumber& other) {
  if (other.value >= value) {
    throw "Römische Zahlen dürfen nicht negativ werden!"s;
  }
  value -= other.value;
  return *this;
}

RomanNumber& operator*=(RomanNumber& op1, const RomanNumber& op2) {
  op1.value *= op2.value;
  return op1;
}

RomanNumber& operator/=(RomanNumber& op1, const RomanNumber& op2) {
  op1.value /= op2.value;
  return op1;
}

RomanNumber operator+(const RomanNumber& lhs,const RomanNumber& rhs) {
  return RomanNumber(lhs) += rhs;
}

RomanNumber operator-(const RomanNumber& lhs,const RomanNumber& rhs) {
  if (rhs.value >= lhs.value) {
      throw "Römische Zahlen dürfen nicht negativ werden!"s;
  }
  return RomanNumber(lhs.value - rhs.value);
}

RomanNumber operator*(const RomanNumber& lhs,const RomanNumber& rhs) {
  // nicht möglich, da wir ein temporäres Objekt nicht an eine
  // non-const-reference binden dürfen - daher sollte man die arithmetischen
  // Zuweisungsoperatoren immer als Methode realisieren!
  // return RomanNumber(lhs) *= rhs;
  return RomanNumber(lhs.value * rhs.value);
}

RomanNumber operator/(const RomanNumber& lhs,const RomanNumber& rhs) {
  // return RomanNumber(lhs) /= rhs;
  return RomanNumber(lhs.value / rhs.value);
}

bool operator==(const RomanNumber& lhs,const RomanNumber& rhs) {
  return lhs.value == rhs.value;
}

bool operator!=(const RomanNumber& lhs,const RomanNumber& rhs) {
  return ! (lhs == rhs);
}

bool operator<=(const RomanNumber& lhs,const RomanNumber& rhs) {
  return lhs.value <= rhs.value;
}

bool operator>=(const RomanNumber& lhs,const RomanNumber& rhs) {
  return lhs.value >= rhs.value;
}

RomanNumber& RomanNumber::operator++() {
  value += 1;
  return *this;
}

RomanNumber RomanNumber::operator++(int) {
  RomanNumber old( *this );
  ++*this;
  return old;
}

RomanNumber& operator--(RomanNumber& rn) {
  rn.value--;
  if (rn.value == 0) {
    throw "Römische Zahlen dürfen nicht null werden!"s;
  }
  return rn;
}

RomanNumber operator--(RomanNumber& rn,int) {
  RomanNumber old( rn );
  rn.value--;
  if (rn.value == 0) {
    throw "Römische Zahlen dürfen nicht null werden!"s;
  }
  return old;
}

RomanNumber RomanNumber::operator+() const {
  return RomanNumber( *this );
}

RomanNumber operator-(const RomanNumber&) {
  throw "Negative Römische Zahlen sind nicht erlaubt"s;
}

