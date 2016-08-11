// correct. Vechile default to private
class CADVehicle : public CAD, Vehicle { };
// error: List occurs two times
class DblList : public List, public List { };
// correct
class iostream : public istream, public ostream { };
