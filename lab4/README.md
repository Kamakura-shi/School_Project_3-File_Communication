# Lab2-15



## Getting started

To make it easy for you to get started with GitLab, here's a list of recommended next steps.

Already a pro? Just edit this README.md and make it your own. Want to make it easy? [Use the template at the bottom](#editing-this-readme)!

## Add your files

- [ ] [Create](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#create-a-file) or [upload](https://docs.gitlab.com/ee/user/project/repository/web_editor.html#upload-a-file) files
- [ ] [Add files using the command line](https://docs.gitlab.com/ee/gitlab-basics/add-file.html#add-a-file-using-the-command-line) or push an existing Git repository with the following command:

```
cd existing_repo
git remote add origin https://gitlab.ele.etsmtl.ca/AQ91380/lab2-15.git
git branch -M main
git push -uf origin main
```

## Integrate with your tools

- [ ] [Set up project integrations](https://gitlab.ele.etsmtl.ca/AQ91380/lab2-15/-/settings/integrations)

## Collaborate with your team

- [ ] [Invite team members and collaborators](https://docs.gitlab.com/ee/user/project/members/)
- [ ] [Create a new merge request](https://docs.gitlab.com/ee/user/project/merge_requests/creating_merge_requests.html)
- [ ] [Automatically close issues from merge requests](https://docs.gitlab.com/ee/user/project/issues/managing_issues.html#closing-issues-automatically)
- [ ] [Enable merge request approvals](https://docs.gitlab.com/ee/user/project/merge_requests/approvals/)
- [ ] [Automatically merge when pipeline succeeds](https://docs.gitlab.com/ee/user/project/merge_requests/merge_when_pipeline_succeeds.html)

## Test and Deploy

Use the built-in continuous integration in GitLab.

- [ ] [Get started with GitLab CI/CD](https://docs.gitlab.com/ee/ci/quick_start/index.html)
- [ ] [Analyze your code for known vulnerabilities with Static Application Security Testing(SAST)](https://docs.gitlab.com/ee/user/application_security/sast/)
- [ ] [Deploy to Kubernetes, Amazon EC2, or Amazon ECS using Auto Deploy](https://docs.gitlab.com/ee/topics/autodevops/requirements.html)
- [ ] [Use pull-based deployments for improved Kubernetes management](https://docs.gitlab.com/ee/user/clusters/agent/)
- [ ] [Set up protected environments](https://docs.gitlab.com/ee/ci/environments/protected_environments.html)

***

# Editing this README

When you're ready to make this README your own, just edit this file and use the handy template below (or feel free to structure it however you want - this is just a starting point!). Thank you to [makeareadme.com](https://www.makeareadme.com/) for this template.

## Suggestions for a good README
Every project is different, so consider which of these sections apply to yours. The sections used in the template are suggestions for most open source projects. Also keep in mind that while a README can be too long and detailed, too long is better than too short. If you think your README is too long, consider utilizing another form of documentation rather than cutting out information.

## Name
Recherche de base de données IMDb 

## Description
Dans ce projet, notre but est de permettre à un utilisateur de faire une recherche à travers une base de données IMDb. 

Pour ce faire, il faut permettre au programme d'éxtraire les résultats dans un fichier TSV. 

Ensuite, explore la base de données de titres pour identifier ceux de la base de donnée crée par l'utilisateur. Pour que l'utilisateur puisse arriver au titre recherché, le programme manipule les bases de données crées pour faire en sorte que les mots clés entrés concordent avec le titre recherché.

Enfin, nous avons implémenté un module de fonctions de tests qui nous donne les résultats voulu pour les fonctions basiques de recherche.

## Badges
On some READMEs, you may see small images that convey metadata, such as whether or not all the tests are passing for the project. You can use Shields to add some to your README. Many services also have instructions for adding a badge.

## Visuals
Voici une démonstration du fonctionnement :

[![Fonctionne.png](https://i.postimg.cc/qq80N28b/Fonctionne.png)](https://postimg.cc/ZvKXgBsp)

## Installation
Ce programme est écrit en C à 100%, il se peut que vous ayez à changer des noms de fonctions si vous utilisez un environnement de programmation C/C++. Par exemple, vous auriez peut-être à modifier le nom de la fonction strdup pour qu'elle devienne _strdup. Si vous décidez d'utiliser Microsoft Visual Studio Code, n'oubliez pas d'installer le main séparément des fichiers sources.

## Usage
Pour vérifier si le projet fonctionne, on peut écrire une commande dans le terminal qui nous renvoie le résultat de recherche. Un exemple d'éxécution serait : ./Debug/main -t "The Matrix" -c "Action,Sci-Fi" -a "1990:2000". Le résulat devrait être écrit de la manière suivante :

Titre : The Matrix
Catégorie : Action,Sci-Fi
Années : 1990:2000

## Support
Tell people where they can go to for help. It can be any combination of an issue tracker, a chat room, an email address, etc.

## Roadmap
If you have ideas for releases in the future, it is a good idea to list them in the README.

## Contributing
State if you are open to contributions and what your requirements are for accepting them.

For people who want to make changes to your project, it's helpful to have some documentation on how to get started. Perhaps there is a script that they should run or some environment variables that they need to set. Make these steps explicit. These instructions could also be useful to your future self.

You can also document commands to lint the code or run tests. These steps help to ensure high code quality and reduce the likelihood that the changes inadvertently break something. Having instructions for running tests is especially helpful if it requires external setup, such as starting a Selenium server for testing in a browser.

## Authors and acknowledgment
Par Hani Ouali et Samuel Yactayo-Goulet

## License
For open source projects, say how it is licensed.

## Project status
If you have run out of energy or time for your project, put a note at the top of the README saying that development has slowed down or stopped completely. Someone may choose to fork your project or volunteer to step in as a maintainer or owner, allowing your project to keep going. You can also make an explicit request for maintainers.
