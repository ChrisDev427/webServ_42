<?php

if (isset($_FILES['file'])) {
    $target_file = basename($_FILES['file']['name']);

    if (move_uploaded_file($_FILES['file']['tmp_name'], $target_file)) {
        echo "Le fichier a été téléchargé.";
    } else {
        echo "Erreur lors du téléchargement du fichier.";
    }
} else {
    echo "Aucun fichier n'a été téléchargé.";
}


?>

