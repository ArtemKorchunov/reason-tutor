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