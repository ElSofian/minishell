# Minishell – 42 Paris

![minishell](https://img.shields.io/badge/42Paris-Minishell-blue)

## 📖 Description

Le projet **Minishell** consiste à créer un interpréteur de commandes basique (shell) en C, en respectant les spécifications imposées par l’école 42 Paris. L’objectif est de reproduire le fonctionnement d’un shell minimaliste en implémentant :

- La lecture et l’analyse (parsing) de la ligne de commande
- La gestion des redirections (`>`, `<`, `>>`, `<<`)
- La gestion des tubes (pipes) (`|`)
- Les variables d’environnement
- Les commandes internes (builtins)
- La gestion des signaux (Ctrl-C, Ctrl-D, Ctrl-\)
- La gestion des erreurs (code de sortie, messages appropriés)

Ce shell ne vise pas à être complet comme Bash ou Zsh, mais à respecter précisément les contraintes du sujet afin de valider les acquis sur la gestion des processus, la manipulation de chaînes et la compréhension de l’environnement UNIX.

---

## 🛠️ Prérequis

- Un environnement UNIX (Linux ou macOS)
- Un compilateur C (gcc)
- La librairie standard (`libft`) développée dans les projets 42 antérieurs (pour certaines fonctions de bas niveau, si souhaité)
- Make (ou tout autre outil de compilation)

---

## 🚀 Installation & Compilation

1. **Cloner le dépôt**  
   ```bash
   git clone https://github.com/ElSofian/minishell.git
   cd minishell
   make
   ./minishell

## 🖋️ Crédits
Elaloui Sofian & Balthazar Borry
