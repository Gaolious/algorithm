<?php

    $n = rand(1,100);

    echo $n . "\n";
    for ( $y=0 ; $y < $n ; $y ++)
    {
        for ( $x=0 ; $x < $n ; $x ++)
            echo rand(-127, 127) . " ";
        echo "\n";
    }
