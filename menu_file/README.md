# Unit Browser for a Mythical Game

To represent the units and weapons shown in the GUI, you need to implement the
required classes for storing the units' data. You may implement any
class hierarchy that will fulfill the needs of storing and making accessible
the relevant information. You're also free to select the data types that you
deem best for the individual pieces of information.
The diagram below offers one possible approach.

```mermaid

classDiagram


class Weapon {
  + Weapon(.)
  + is_ranged() bool
  + damage() uint32_t
  + strikes() uint32_t
  + type() WeaponType

  - string name_;
  - uint32_t damage_;
  - uint32_t strikes_;
  - WeaponType type_;
  - bool is_ranged_;
}


class Unit {
  + Unit(.)

  + type_name() string
  + name() string
  + max_health() uint32_t
  + moves() uint32_t
  + weapons() Container<Weapon>

  - string type_name_;
  - string name_;
  - uint32_t max_health_;
  - uint32_t moves_;
  - Container<Weapon> weapons_;
}

Unit *-- Weapon
```
