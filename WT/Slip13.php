<!--
Q.1) Write a PHP script to create a chess board using CSS on table cells.
-->
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
        }
        table {
            border-collapse: collapse;
            margin: 20px auto;
        }
        td {
            width: 50px;
            height: 50px;
            text-align: center;
            border: 1px solid #000;
        }
        .white {
            background-color: #fff;
        }
        .black {
            background-color: #888;
        }
    </style>
</head>
<body>

<?php
echo '<table>';
for ($row = 1; $row <= 8; $row++) {
    echo '<tr>';
    for ($col = 1; $col <= 8; $col++) {
        $class = ($row + $col) % 2 == 0 ? 'white' : 'black';
        echo '<td class="' . $class . '"></td>';
    }
    echo '</tr>';
}
echo '</table>';
?>
</body>
</html>