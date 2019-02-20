Js.log("Hello, BuckleScript and Reon!");


/* If statement should return only one type */
let some_value = if (true) {()}


/* Switch operator */
let lamp =
  switch 1 {
  | 1 => "one"
  | 2 => "two"
  | _ => "nothing"
  };

let lamp_1 =
  switch 1 {
  | 1 => "one"
  | 2 => "two"
  | other => {
    print_endline("Invalid value: " ++ string_of_int(other));
    "off";
  }
  };

/* Record */

type person = {
  name: string,
  age: int,
};

let person = { name: "Anna", age: 28 }

let tim = {
  name: "Tim",
  age: 52,
};

let tim: person = { name: "Tim", age: 52 };

/* tim.size; - will get warning */

let { age: timsAge, name: timsName } = tim;

let {name} = tim;

/* Destructuring (immutable changes) */
let oderTim = {
  name: tim.name,
  age: tim.age + 1,
};

let olderTim: person = {name: "Tim", age: 53 };

let evenOlderTim = {
  ...olderTim,
  age: 53
};

/* Mutable changes */

type animal = {
  species: string,
  mutable scary: bool,
};

let lion = {
  species: "Lion",
  scary: true,
};
/* automatically defines a type an `animal` for variable lion*/

lion.scary = false;

let anna = {
  pub name = "Anna";
  pub eyecolor = "brown";
};

anna#eyecolor;

/* Variants */

type answer =
  | Yes
  | No
  | Maybe;

let isReasonGreat = Maybe;

let message =
  switch isReasonGreat {
  | Yes => "HellYeah"
  | No => "((("
  | Maybe => "Keep learning"
  };

type item =
  | Note(string)
  | Todo(string, bool);

let myItem = Todo("redesign website", false);