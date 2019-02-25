type coordinates('a) = ('a, 'a);

let coord_1: coordinates(int) = (10, 20);
let coord_2: coordinates(float) = (2.3, 4.4);


type ourOption('a) =
  | OurNone
  | OurSome('a);

OurSome("2");
/* - : ourOption(string) = OurSome("Vienna") */
OurSome(42);
/* - : ourOption(int) = OurSome(42) */

type ship('a, 'b) = {
  name: 'a,
  age: 'b
};

let ship_1 = { name: "John", age: 52 };