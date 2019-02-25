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

let message =
  switch myItem {
  | Note(text) => "Here is your note" ++ text;
  | Todo("redesign website", false) => "Matche value"; 
  | Todo(text, chekced) => "Here is your todo: " ++ text ++ string_of_bool(chekced);
  };

/* Eliminate illegal states */

type request = 
  | Loading
  | Error
  | Success(string)

let state = Loading;

let ui =
  switch (state) {
  | Loading => "Loading..."
  | Error => "Something went wrong"
  | Success("") => "Your name is missing"
  | Success(name) => "Your name is " ++ name
  };


type userResponse = {
  id: int,
  name: string,
  age: int,
};

type requestObject =
  | Loading
  | Error
  | Success(userResponse);

let response = Success({ id: 5, name: "Artem", age: 45 });

let ui =
  switch (response){
  | Loading => "Request is loading now!"
  | Error => "Something went wrong!"
  | Success(userResponse) => "Your name is: " ++ userResponse.name
  };

/* Optional values */

let meaningfulValue = None;

let meaningfulValue = Some("42");


let meaningfulResult =
  switch meaningfulValue {
  | None => "This is none value"
  | Some(value) => "Current value: " ++ value
  };