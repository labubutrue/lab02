# Laboratory work II

Данная лабораторная работа посвящена изучению систем контроля версий на примере Git.

Репозиторий: [labubutrue/lab02](https://github.com/labubutrue/lab02)

---

# Part I

## 1. Создать пустой репозиторий на сервисе github.com

Публичный репозиторий `lab02` создан:

`https://github.com/labubutrue/lab02`

---

## 2. Выполнить инструкцию по созданию первого коммита на странице репозитория

### Команда

```bash
mkdir -p ~/tp-labs/lab02
```

### Команда

```bash
cd ~/tp-labs/lab02
```

### Команда

```bash
git init
```

### Вывод

```text
Initialized empty Git repository in /Users/mac/tp-labs/lab02/.git/
```

### Команда

```bash
git branch -M main
```

### Команда

```bash
git config --global user.name "labubutrue"
```

### Команда

```bash
git config --global user.email "chimichanga2123837@gmail.com"
```

### Команда

```bash
echo "# lab02" >> README.md
```

### Команда

```bash
git add README.md
```

### Команда

```bash
git commit -m "Initial commit"
```

### Вывод

```text
[main (root-commit) 1e4df39] Initial commit
 1 file changed, 1 insertion(+)
 create mode 100644 README.md
```

### Команда

```bash
git remote add origin https://github.com/labubutrue/lab02.git
```

### Команда

```bash
git push -u origin main
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 225 bytes | 225.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/labubutrue/lab02.git
 * [new branch]      main -> main
branch 'main' set up to track 'origin/main'.
```

</details>

---

## 3. Создать файл `hello_world.cpp` и реализовать Hello World в плохом стиле

### Команда

```bash
nano hello_world.cpp
```

Содержимое файла:

```cpp
#include <iostream>
using namespace std;

int main(){
cout<<"Hello world"<<endl;
return 0;
}
```

---

## 4. Добавить файл в локальную копию репозитория

### Команда

```bash
git add hello_world.cpp
```

---

## 5. Закоммитить изменения с осмысленным сообщением

### Команда

```bash
git commit -m "Add hello world program (bad style)"
```

### Вывод

```text
[main 3b1abb3] Add hello world program (bad style)
 1 file changed, 7 insertions(+)
 create mode 100644 hello_world.cpp
```

---

## 6. Изменить программу: запросить имя пользователя и вывести `Hello world from @name`

### Команда

```bash
nano hello_world.cpp
```

Содержимое файла после изменения:

```cpp
#include <iostream>
using namespace std;

int main(){
string name;
cin>>name;
cout<<"Hello world from "<<name<<endl;
return 0;
}
```

---

## 7. Закоммитить новую версию программы

Повторный `git add` не требуется, так как `hello_world.cpp` уже отслеживается Git, а параметр `-a` автоматически добавляет изменения отслеживаемых файлов в индекс перед коммитом.

### Команда

```bash
git commit -am "Add user input and greeting"
```

### Вывод

```text
[main fac09a0] Add user input and greeting
 1 file changed, 3 insertions(+), 1 deletion(-)
```

---

## 8. Запушить изменения в удалённый репозиторий

### Команда

```bash
git push origin main
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 10 threads
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 760 bytes | 760.00 KiB/s, done.
Total 6 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/labubutrue/lab02.git
   1e4df39..fac09a0  main -> main
```

</details>

---

## 9. Проверить историю коммитов

### Команда

```bash
git log --oneline --all --graph
```

### Вывод

```text
* fac09a0 (HEAD -> main, origin/main) Add user input and greeting
* 3b1abb3 Add hello world program (bad style)
* 1e4df39 Initial commit
```

---

# Part II

Работа продолжается с тем же репозиторием.

## 1. Создать локальную ветку `patch1`

### Команда

```bash
git checkout -b patch1
```

### Вывод

```text
Switched to a new branch 'patch1'
```

---

## 2. Исправить стиль кода и избавиться от `using namespace std;`

### Команда

```bash
nano hello_world.cpp
```

Содержимое файла после изменения:

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Hello world from " << name << std::endl;
    return 0;
}
```

---

## 3. Закоммитить и запушить локальную ветку в удалённый репозиторий

### Команда

```bash
git commit -am "Fix code style, remove using namespace std"
```

### Вывод

```text
[patch1 8ae9157] Fix code style, remove using namespace std
 1 file changed, 8 insertions(+), 6 deletions(-)
```

### Команда

```bash
git push -u origin patch1
```

### Вывод первой попытки

```text
fatal: unable to access 'https://github.com/labubutrue/lab02.git/': Could not resolve host: github.com
```

Команда была выполнена повторно после восстановления сетевого доступа.

### Команда

```bash
git push -u origin patch1
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 10 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 438 bytes | 438.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'patch1' on GitHub by visiting:
remote:      https://github.com/labubutrue/lab02/pull/new/patch1
remote:
To https://github.com/labubutrue/lab02.git
 * [new branch]      patch1 -> patch1
branch 'patch1' set up to track 'origin/patch1'.
```

</details>

---

## 4. Проверить, что ветка `patch1` доступна в удалённом репозитории

### Команда

```bash
git branch -a
```

### Вывод

```text
  main
* patch1
  remotes/origin/main
  remotes/origin/patch1
```

---

## 5. Создать pull-request `patch1 -> main`

Pull request `patch1 -> main` создан на GitHub.

---

## 6. Добавить комментарии в исходный код в ветке `patch1`

### Команда

```bash
nano hello_world.cpp
```

В исходный код добавлены комментарии.

---

## 7. Commit, push

### Команда

```bash
git commit -am "Add comments in patch1"
```

### Вывод

```text
[patch1 0934096] Add comments in patch1
 1 file changed, 3 insertions(+)
```

### Команда

```bash
git push origin patch1
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 10 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 513 bytes | 513.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/labubutrue/lab02.git
   8ae9157..0934096  patch1 -> patch1
```

</details>

---

## 8. Проверить, что новые изменения появились в созданном pull-request

Изменения проверены на сайте GitHub. Новый коммит из ветки `patch1` появился в ранее созданном pull request.

---

## 9. Выполнить слияние PR `patch1 -> main` и удалить удалённую ветку `patch1`

Pull request был объединён на сайте GitHub. Удалённая ветка `patch1` была удалена после merge.

---

## 10. Локально получить изменения из `main` и просмотреть историю

### Команда

```bash
git checkout main
```

### Вывод

```text
Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

### Команда

```bash
git pull origin main
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 892 bytes | 446.00 KiB/s, done.
From https://github.com/labubutrue/lab02
 * branch            main       -> FETCH_HEAD
   fac09a0..fccf52c  main       -> origin/main
Updating fac09a0..fccf52c
Fast-forward
 hello_world.cpp | 17 +++++++++++------
 1 file changed, 11 insertions(+), 6 deletions(-)
```

</details>

### Команда

```bash
git log
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
commit ac792879c27451cb895aa73882a797311bab7011 (HEAD -> main, origin/main)
Merge: 9e964de db44d5b
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 01:50:36 2026 +0300

    Merge pull request #2 from labubutrue/patch2

    patch2 clang-format

commit db44d5b2ab6cdf253fd56c5ba8a7b2bfc752f9e1 (origin/patch2, patch2)
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 01:31:24 2026 +0300

    Apply clang-format Mozilla style

commit 9e964dea493543ad103d670e4fcfbe644b261f11
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 01:33:33 2026 +0300

    Refactor hello_world.cpp

commit fccf52ca17c6348eb21346483c153d2e70270a92
Merge: fac09a0 0934096
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 01:11:15 2026 +0300

    Merge pull request #1 from labubutrue/patch1

    patch1 changes

commit 0934096451df2f517d86d9d00ed0a953cf263eca (origin/patch1)
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 01:10:12 2026 +0300

    Add comments in patch1

commit 8ae91579a846e1fcf859f8dd11bfb170b541bfdd
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 01:03:54 2026 +0300

    Fix code style, remove using namespace std

commit fac09a09e5fdaf09c2c9d7ec0e5381aa505fc468
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 00:52:37 2026 +0300

    Add user input and greeting

commit 3b1abb37f51f8d2c6f897c7e3509128df15f8f18
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 00:47:28 2026 +0300

    Add hello world program (bad style)

commit 1e4df3961cfd0b93e7b87583afee4dd37b9046f7
Author: labubutrue <chimichanga2123837@gmail.com>
Date:   Thu Sep 3 00:41:56 2026 +0300

    Initial commit
```

</details>


---

## 11. Удалить локальную ветку `patch1`

### Команда

```bash
git branch -d patch1
```

### Вывод

```text
Deleted branch patch1 (was 0934096).
```

---

# Part III

Работа продолжается с тем же репозиторием.

## 1. Создать новую локальную ветку `patch2`

### Команда

```bash
git checkout -b patch2
```

### Вывод

```text
Switched to a new branch 'patch2'
```

---

## 2. Изменить code style с помощью `clang-format`, используя стиль Mozilla

### Команда

```bash
clang-format --version
```

### Вывод

```text
clang-format version 22.1.6
```

### Команда

```bash
clang-format -i -style=Mozilla hello_world.cpp
```

---

## 3. Commit, push, создать pull-request `patch2 -> main`

### Команда

```bash
git commit -am "Apply clang-format Mozilla style"
```

### Вывод

```text
[patch2 683365d] Apply clang-format Mozilla style
 1 file changed, 7 insertions(+), 6 deletions(-)
```

### Команда

```bash
git push -u origin patch2
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 10 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 393 bytes | 393.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
remote:
remote: Create a pull request for 'patch2' on GitHub by visiting:
remote:      https://github.com/labubutrue/lab02/pull/new/patch2
remote:
To https://github.com/labubutrue/lab02.git
 * [new branch]      patch2 -> patch2
branch 'patch2' set up to track 'origin/patch2'.
```

</details>

Pull request `patch2 -> main` создан на GitHub.

### Команда

```bash
git branch
```

### Вывод

```text
  main
* patch2
```

---

## 4. В ветке `main` удалённого репозитория изменить комментарии

Комментарий был изменён непосредственно в ветке `main` на GitHub, чтобы получить изменение того же участка файла независимо от ветки `patch2`.

Для гарантированного конфликта тот же комментарий затем был изменён локально в `patch2`.

### Команда

```bash
nano hello_world.cpp
```

### Команда

```bash
git commit -am "Modify comment in patch2"
```

### Вывод

```text
[patch2 13ed00d] Modify comment in patch2
 1 file changed, 1 insertion(+), 1 deletion(-)
```

### Команда

```bash
git push origin patch2
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 10 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 371 bytes | 371.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/labubutrue/lab02.git
   683365d..13ed00d  patch2 -> patch2
```

</details>

---

## 5. Убедиться, что в pull-request появились конфликты

На сайте GitHub проверено, что в pull request `patch2 -> main` появился конфликт.

---

## 6. Исправить конфликт с помощью pull/fetch + rebase

### Команда

```bash
git fetch origin main
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
remote: Enumerating objects: 5, done.
remote: Counting objects: 100% (5/5), done.
remote: Compressing objects: 100% (3/3), done.
remote: Total 3 (delta 1), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (3/3), 979 bytes | 244.00 KiB/s, done.
From https://github.com/labubutrue/lab02
 * branch            main       -> FETCH_HEAD
   fccf52c..9e964de  main       -> origin/main
```

</details>

### Команда

```bash
git rebase origin/main
```

### Вывод

<details>
<summary>Показать полный вывод конфликта</summary>

```text
Auto-merging hello_world.cpp
CONFLICT (content): Merge conflict in hello_world.cpp
error: could not apply 13ed00d... Modify comment in patch2
hint: Resolve all conflicts manually, mark them as resolved with
hint: "git add/rm <conflicted_files>", then run "git rebase --continue".
hint: You can instead skip this commit: run "git rebase --skip".
hint: To abort and get back to the state before "git rebase", run "git rebase --abort".
Could not apply 13ed00d... Modify comment in patch2
```

</details>

Конфликт был исправлен вручную в файле `hello_world.cpp`: удалены конфликтные маркеры и оставлена корректная итоговая версия комментария.

### Команда

```bash
nano hello_world.cpp
```

### Команда

```bash
git add hello_world.cpp
```

### Команда

```bash
git rebase --continue
```

### Вывод

```text
Successfully rebased and updated refs/heads/patch2.
```

---

## 7. Сделать force push в ветку `patch2`

### Команда

```bash
git push origin patch2 --force
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
Enumerating objects: 5, done.
Counting objects: 100% (5/5), done.
Delta compression using up to 10 threads
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 399 bytes | 399.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/labubutrue/lab02.git
 + 13ed00d...db44d5b patch2 -> patch2 (forced update)
```

</details>

---

## 8. Убедиться, что в pull-request пропали конфликты

После `force push` pull request на GitHub был обновлён. Конфликт исчез.

---

## 9. Вмержить pull-request `patch2 -> main`

Pull request `patch2 -> main` был объединён на сайте GitHub.

После merge локальная ветка `main` была синхронизирована с удалённым репозиторием.

### Команда

```bash
git checkout main
```

### Вывод

```text
Switched to branch 'main'
Your branch is behind 'origin/main' by 1 commit, and can be fast-forwarded.
  (use "git pull" to update your local branch)
```

### Команда

```bash
git pull origin main
```

### Вывод

<details>
<summary>Показать полный вывод</summary>

```text
remote: Enumerating objects: 1, done.
remote: Counting objects: 100% (1/1), done.
remote: Total 1 (delta 0), reused 0 (delta 0), pack-reused 0 (from 0)
Unpacking objects: 100% (1/1), 898 bytes | 449.00 KiB/s, done.
From https://github.com/labubutrue/lab02
 * branch            main       -> FETCH_HEAD
   9e964de..ac79287  main       -> origin/main
Updating fccf52c..ac79287
Fast-forward
 hello_world.cpp | 15 ++++++++-------
 1 file changed, 8 insertions(+), 7 deletions(-)
```

</details>

---

# Результат

В ходе лабораторной работы были выполнены:

- создание и настройка Git-репозитория;
- создание и публикация коммитов;
- работа с ветками `patch1` и `patch2`;
- создание и обновление pull request;
- merge изменений;
- применение `clang-format` со стилем Mozilla;
- создание merge-конфликта;
- разрешение конфликта через `rebase`;
- принудительная публикация переписанной истории с помощью `git push --force`.
