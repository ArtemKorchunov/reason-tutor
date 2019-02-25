/*
! keep the usage locally -> tuples
! update the structures that are long-living and passed around often -> records
*/

/* Tuples --------------------------------------------------------------------- */

("Anna", 5);

type point = (int, int);

let myPoint: point = (3, 4);
let myPoint = (3, 4);
let myPoint = (3, "Anna");

/* retrieve first element fst */
fst((0, 2));
/* - : int = 0 */
/* retrieve second element fst */
snd((0, 2));
/* - : int = 2 */

/* desctructure */
let (x, y, z) = (1, 2, 3);
z;
/* - : int = 3 */

/* omit values except z */
let (_, _, z) = (1, 2, 3);

let anotherPoint = (fst(myPoint), 6);


/* Lists --------------------------------------------------------------------- */
let myList = [1, 2, 3];

type item =
  | Measure(int)
  | Note(string);

let myList = [Measure(4), Note("Hello")];


/* Incorrect defining ! */
/* type item =
  | int
  | string; */

List.append([1, 2, 3], [1, 5]);
/* - : list(int) = [1, 2, 3, 1, 5] */
[1, 2, 3] @ [1, 5];
/* - : list(int) = [1, 2, 3, 1, 5] */

/* 
  Below is only for appending ! 
  [...[1, 2, 3], 0] -> this will cause an error
*/
[0, ...[1, 2, 3]]
/* - : list(int) = [0, 1, 2, 3] */

let myList = [1, 2, 3];

let message =
  switch myList {
  | [] => "Missing variable"
  | [head, ...rest] => "Head is: " ++ string_of_int(head);
  };
/* let message: string = "Head is: 1" */
List.nth([2, 4], 0);
/* - : int = 2 */

/* Arrays --------------------------------------------------------------------- */
/*
  Arrays is immutable
  List is mutable
*/
let myArray = [|1, 2|];

myArray[0];

myArray[0] = 7;

/*  Structural(deep) equality -> == */
/*  Referential equality -> === */

type person = {name: string, age: int};

(true, [{name: "Tim", age: 28}]) == (true, [{name: "Tim", age: 28}]);
/* - : bool = true */
(true, [{name: "Tim", age: 28}]) == (true, [{name: "Tim", age: 27}]);
/* - : bool = false */

/* Tuples - pattern matching using switch */
let myTodo = ("Anna", false);

let message =
  switch myTodo {
  | (_, false) => "Decline todo"
  | ("redesign website", _) => "Redesigned"
  | (text, true) => "Todo" ++ text ++ " " ++ string_of_bool(true);
  };

let myTodo = ("Anna", (1, 2));

switch myTodo {
| ("Anna", (_, _) as numberPair) => "Anna" ++ " " ++ string_of_int(fst(numberPair))
| (text, (_, second) as numberPair) => text ++ " " ++ string_of_int(fst(numberPair)) ++ " " ++ string_of_int(second)
};
/* List - pattern matching using switch */

let myTodo = ["a", "b", "c"];

let message =
  switch (myTodo) {
  | [_, _, "c"] => "Your last element is c"
  | [_, _, lastValue] => "Your last element is " ++ lastValue
  | [head, ...tail] => "Your head is: " ++ head
  | [] => "Your array is empty"
  };

/* Array - pattern matching using switch */

let myTodo = [|"a", "b", "c"|];

let message =
  switch myTodo {
  | [|"a", "b", _|] => "First two elements exist"
  | [|x, y, _|] => "First two elements are" ++ " " ++ x ++ " " ++ y;
  | _ => {
    print_endline("Nothing was found!");
    "Oops!"
  }
  };

/* Records - pattern matching using switch */

type todo = {
  goal: string,
  name: string
};

let myTodo = { goal: "Achieve success", name: "Anna" };

let message =
  switch myTodo {
  | { goal, name: "Anna" } => "Anna`s goal is: " ++ goal;
  | _ => "You are not ought to have a goal )))"
  };


/* type Notes(...) and others - pattern matching using switch */

type someGoals = 
  | Goal(string)
  | Note(string);

let goals = Goal("Be a hero!");

let message =
  switch goals {
  | Goal("Be a hero!") => "You won't be a hero"
  | Goal(text) => "Your goal is: " ++ text
  | Note(text) => "Notes: " ++ text
  };

let someValue = 2;

let message =
  switch someValue {
  | 1 | 2 | 3 => "Your valyes is lower than 5"
  | _ => "Your value"
  };

type request =
  | Error(int)
  | Success(string);

let response = Error(501);

switch response {
| Error(501 | 502 | 503 ) => "Server has some problems"
| Success(text) => "Success message: " ++ text
| Error(errorCode) => "Error code is: " ++ string_of_int(errorCode)
};

type requestNew =
  | Error(int)
  | Success(string)
  | NotRequested

let isServerError = code => code >= 500 && code <= 511;

switch (Error(502)) {
  | Error(code) when isServerError(code)=> "Server has some problems"
  | Success(text) => "Success message: " ++ text
  | Error(errorCode) => "Error code is: " ++ string_of_int(errorCode)
  | _ => "Something go really wrong!"
};

/* Ternary conditional */
let message = true ? "Good monring" : "Hello";