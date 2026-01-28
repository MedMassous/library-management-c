# 📚 Système de Gestion de Bibliothèque

## 🎯 Vue d'Ensemble

Ce projet est un système complet de gestion de bibliothèque développé en C. Il permet de gérer une collection de livres avec toutes les opérations nécessaires: ajout, recherche, emprunt, modification, suppression, statistiques et export de rapports.


---

## 📋 Fonctionnalités

### Fonctionnalités de Base
1. ✅ **Ajouter un livre** - Ajouter de nouveaux livres à la bibliothèque
2. ✅ **Rechercher un livre** - Rechercher par titre ou auteur
3. ✅ **Afficher tous les livres** - Liste complète avec récursion
4. ✅ **Emprunter un livre** - Marquer un livre comme emprunté
5. ✅ **Retourner un livre** - Marquer un livre comme disponible

### Fonctionnalités Avancées (NOUVEAU!)
6. ✅ **Supprimer un livre** - Retirer un livre de la collection
7. ✅ **Modifier un livre** - Changer les informations d'un livre
8. ✅ **Afficher les statistiques** - Vue d'ensemble avec comptage récursif
9. ✅ **Filtrer les livres** - Afficher seulement disponibles ou empruntés (récursif)
10. ✅ **Trier les livres** - Trier par titre, auteur ou année
11. ✅ **Exporter un rapport** - Générer un rapport texte complet

### Fonctionnalités Système
12. ✅ **Sauvegarder automatiquement** - Sauvegarde dans un fichier texte
13. ✅ **Charger automatiquement** - Chargement au démarrage

---

## 🔧 Compilation et Exécution

### Compiler
```bash
gcc bibliotheque_enhanced.c -o bibliotheque
```

### Exécuter
```bash
./bibliotheque
```

---

## 📁 Structure du Projet

```
.
├── bibliotheque_enhanced.c         # Code source principal
├── bibliotheque.txt                # Fichier de sauvegarde (généré)
├── rapport_bibliotheque.txt        # Rapport exporté (généré)
├── NOUVELLES_FONCTIONNALITES.md    # Documentation des ajouts
├── COMPARAISON.md                  # Avant/Après
├── SCENARIO_DEMONSTRATION.md       # Guide de présentation
└── README.md                       # Ce fichier
```

---

## 💻 Concepts C Utilisés

### ✅ Structures (struct)
- `Livre` - Structure pour stocker les informations d'un livre
- `Bibliotheque` - Structure contenant un tableau de livres

### ✅ Pointeurs
- Passage par référence dans toutes les fonctions de modification
- Manipulation efficace des structures
- Accès direct aux données sans copies

### ✅ Récursion (4 fonctions récursives!)
1. `afficherLivresRecursif()` - Affichage récursif
2. `compterDisponiblesRecursif()` - Comptage récursif avec retour
3. `compterEmpruntesRecursif()` - Comptage récursif avec condition
4. `afficherLivresFiltresRecursif()` - Affichage conditionnel récursif

### ✅ Fichiers Texte
- Sauvegarde des données
- Chargement automatique
- Export de rapports formatés

### ✅ Tableaux
- Stockage des livres
- Manipulation (tri, suppression avec décalage)

### ✅ Chaînes de caractères
- Manipulation avec `strcpy`, `strcmp`, `strstr`
- Validation et recherche
- Conversion en minuscules

### ✅ Fonctions
- Organisation modulaire (21 fonctions)
- Séparation des responsabilités
- Code réutilisable

---

## 🎓 Points Pédagogiques

### Démonstration de Maîtrise

#### Récursion - Niveau Avancé
Le projet ne se contente pas d'une simple récursion d'affichage. Il démontre plusieurs utilisations:
- **Affichage** - Parcours simple
- **Comptage** - Accumulation de résultats
- **Filtrage** - Récursion avec conditions

#### Manipulation d'Arrays
- Ajout d'éléments
- Suppression avec décalage
- Tri (algorithme de tri à bulles)
- Parcours et recherche

#### Gestion de Fichiers
- Lecture et écriture formatées
- Gestion d'erreurs
- Multiples fichiers (données + rapports)

---

## 📊 Statistiques du Code

- **Lignes de code:** ~820
- **Fonctions:** 21
- **Fonctions récursives:** 4
- **Structures:** 2
- **Options du menu:** 12



## 🔍 Exemples d'Utilisation

### Ajouter un livre
```
Option: 1
Titre: Le Petit Prince
Auteur: Antoine de Saint-Exupéry
Année: 1943
→ Livre ajouté avec succès! (ID: 1)
```

### Rechercher
```
Option: 2
Recherche: "prince"
→ Trouve "Le Petit Prince"
```

### Statistiques
```
Option: 8
→ Nombre total de livres : 4
→ Livres disponibles     : 3 (75.0%)
→ Livres empruntés       : 1 (25.0%)
```

### Filtrer
```
Option: 9
Choix: 1 (Disponibles)
→ Affiche uniquement les livres disponibles
```

### Trier
```
Option: 10
Choix: 3 (Par année)
→ Livres triés de 1862 à 1997
```

---

## ✨ Points Forts du Projet

1. **Complet** - Couvre tous les aspects d'une gestion de bibliothèque
2. **Concepts Maîtrisés** - Utilisation variée et appropriée
3. **Récursion Intelligente** - Pas forcée, mais bien intégrée
4. **Code Propre** - Facile à lire et à comprendre
5. **Robuste** - Gestion d'erreurs et validation
6. **Extensible** - Structure permet d'ajouter facilement des fonctions
7. **Professionnel** - Export de rapports, statistiques

---

## 🆚 Comparaison: Original vs Amélioré

| Aspect | Original | Amélioré |
|--------|----------|----------|
| Fonctions | 13 | 21 |
| Menu | 6 options | 12 options |
| Récursion | 1 fonction | 4 fonctions |
| Fichiers | 1 | 2 |

---

## 📝 Validation des Exigences

### Exigences du Projet
- ✅ Écrit en C
- ✅ Facile à comprendre
- ✅ Facile à présenter
- ✅ Utilise TOUS les concepts requis:
  - ✅ Tableaux et chaînes de caractères
  - ✅ Fonctions
  - ✅ Fonctions récursives (4 fonctions!)
  - ✅ Types personnalisés (struct)
  - ✅ Pointeurs
  - ✅ Fichiers texte

---

## 🏆 Conclusion

Ce projet démontre une maîtrise complète des concepts C requis avec:
- Un système fonctionnel et complet
- Une utilisation variée de la récursion
- Une organisation professionnelle du code
- Des fonctionnalités avancées

---




