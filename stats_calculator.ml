let rec read_rides n acc =
  if n = 0 then acc
  else (
    Printf.printf "Enter rides for driver %d: " (List.length acc + 1);
    let input = read_int () in
    read_rides (n - 1) (input :: acc)
  )

let mean lst =
  let sum = List.fold_left (+) 0 lst in
  float_of_int sum /. float_of_int (List.length lst)

let median lst =
  let sorted = List.sort compare lst in
  let len = List.length sorted in
  if len mod 2 = 0 then
    let mid1 = List.nth sorted (len / 2 - 1) in
    let mid2 = List.nth sorted (len / 2) in
    (float_of_int (mid1 + mid2)) /. 2.0
  else
    float_of_int (List.nth sorted (len / 2))

let mode lst =
  let freq = List.fold_left (fun acc x ->
    let count = try List.assoc x acc + 1 with Not_found -> 1 in
    (x, count) :: List.remove_assoc x acc
  ) [] lst in
  let max_count = List.fold_left (fun acc (_, c) -> max acc c) 0 freq in
  List.filter (fun (_, c) -> c = max_count) freq |> List.map fst

let () =
  Printf.printf "Enter number of drivers: ";
  let n = read_int () in
  let rides = read_rides n [] |> List.rev in
  Printf.printf "\nRide Sharing System Statistics\n";
  Printf.printf "Average rides per driver (Mean): %.2f\n" (mean rides);
  Printf.printf "Median rides per driver: %.2f\n" (median rides);
  Printf.printf "Mode(s): ";
  List.iter (Printf.printf "%d ") (mode rides);
  Printf.printf "\n"
