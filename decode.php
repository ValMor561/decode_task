<?php
function decode_message($file_path) {
    $encode = array();
    $file = fopen($file_path, "r");
    if ($file) {
        while (($line = fgets($file)) !== false) {
            $parts = explode(" ", trim($line));
            $numbers = intval($parts[0]);
            $word = $parts[1];
            $encode[$numbers] = $word;
        }
        fclose($file);
    }
    $max_num = max(array_keys($encode));
    $encode_pos = right_side_numbers($max_num);
    $decode_message = "";
    foreach ($encode_pos as $pos) {
        if (isset($encode[$pos])) {
            $decode_message .= $encode[$pos] . " ";
        }
    }
    return $decode_message;
}

function right_side_numbers($max_value) {
    $nums = array();
    $i = 1;
    $k = 2;
    while ($i <= $max_value) {
        $nums[] = $i;
        $i += $k;
        $k += 1;
    }
    return $nums;
}

$file_path = "message_file.txt";
$decoded_message = decode_message($file_path);
echo $decoded_message;
