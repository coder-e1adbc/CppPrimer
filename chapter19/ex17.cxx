using Get = char (Screen::*)() const;
using Get_pos = char (Screen::*)(Screen::pos, Screen::pos) const;
using Set = Screen& (Screen::*)(char);
using Set_pos = Screen& (Screen::*)(Screen::pos, Screen::pos, char);
using Display = Screen& (Screen::*)(std::ostream &);
using Display_const = const Screen& (Screen::*) const;
using Size = Screen::pos (Screen::*)() const;

