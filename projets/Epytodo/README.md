# EpyTodo

EpyTodo est une API RESTful construite avec Node.js et MySQL, permettant de gérer des tâches pour différents utilisateurs. Elle propose des fonctionnalités d'enregistrement, d'authentification, de gestion des utilisateurs et de leurs tâches.

## 🛠️ Technologies utilisées

- Node.js
- Express
- MySQL
- JWT (jsonwebtoken)
- bcryptjs
- dotenv
- mysql2

## 📁 Structure du projet

```bash
.
├── .env
├── package.json
├── epytodo.sql
└── src
├── config
│ └── db.js
├── index.js
├── middleware
│ ├── auth.js
│ └── notFound.js
└── routes
├── auth
│ └── auth.js
├── todos
│ ├── todos.js
│ └── todos.query.js
└── user
├── user.js
└── user.query.js
```


## ⚙️ Configuration

Crée un fichier `.env` à la racine du projet avec les variables suivantes :

```env
MYSQL_DATABASE=epytodo
MYSQL_HOST=localhost
MYSQL_USER=root
MYSQL_ROOT_PASSWORD=yourpassword
PORT=3000
SECRET=your_jwt_secret
```

## 🧱 Base de données

Le fichier epytodo.sql contient le schéma de la base de données, avec deux tables :

    user

    todo

On peut l'importer avec la commande suivante :

```bash
cat epytodo.sql | mysql -u root -p
```

## 🔐 Authentification

Les routes protégées nécessitent un JSON Web Token dans l’en-tête Authorization. Le token peut être obtenu via les routes /register ou /login.
## Authentification
| Méthode |	Route | Description
|:------- |:-----:| ----------:|
| POST | /register | Enregistrer un utilisateur
| POST | /login | Se connecter
## Utilisateurs
| Méthode | Route | Description
|:------- |:-----:| ----------:|
GET	| /user	| Récupérer ses infos
GET	| /user/todos	| Récupérer ses tâches
GET	| /users/:id/email |	Infos d’un utilisateur
PUT |	/users/:id	| Mettre à jour un utilisateur
DELETE |	/users/:id	| Supprimer un utilisateur
## Todos
Méthode |	Route |	Description
|:------- |:-----:| ----------:|
GET |	/todos |	Récupérer toutes les tâches
GET	| /todos/:id |	Récupérer une tâche
POST |	/todos	| Créer une tâche
PUT	| /todos/:id |	Mettre à jour une tâche
DELETE |	/todos/:id |	Supprimer une tâche
## ✅ Exécution du projet
## Installation

```bash
npm install
```

## Lancement

```bash
npm start
```

Le serveur sera accessible sur http://localhost:3000.
## ✅ Bonnes pratiques

- Respect de l'architecture recommandée

- Utilisation de middlewares pour l'authentification et la gestion des erreurs

- Hashage sécurisé des mots de passe

- Gestion cohérente des erreurs avec des messages clairs et codes HTTP appropriés

## 📌 Remarques

- Le dossier node_modules doit être ignoré grâce à .gitignore

- Aucune insertion de données ne doit figurer dans epytodo.sql

- Toutes les réponses de l’API sont au format JSON

## 🙋‍♀️ Auteurs
- [@llosts](https://github.com/llosts)
- [@yohandprt](https://github.com/yohandprt)
- [@Alexandre2806](https://github.com/Alexandre2806)