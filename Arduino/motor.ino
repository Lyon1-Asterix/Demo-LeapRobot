void motor () {
    switch (c) {
    case 2: // Droite
        analogWrite (moteur[0], 150);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 0);
        analogWrite (moteur[3], 0);
        break;

    case 3: // Gauche
        analogWrite (moteur[0], 0);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 0);
        analogWrite (moteur[3], 150);
        break;

    case 4: // Haut
        analogWrite (moteur[0], 150);
        analogWrite (moteur[1], 0);
        analogWrite (moteur[2], 150);
        analogWrite (moteur[3], 0);
        break;

    case 5: // Bas
        analogWrite (moteur[0], 0);
        analogWrite (moteur[1], 150);
        analogWrite (moteur[2], 0);
        analogWrite (moteur[3], 150);
        break;

    default: break;
    }
}
