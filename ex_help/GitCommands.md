
----github commands


git init   vs git clone:
git init : wenn wir locales respository wollten mit git verfolgen
git clone:  macht "git init" automatisch"
-----
git status

git rm example.txt
git rm file1.txt file2.txt file3.txt
git commit -m "Delete files"
git push origin <branch-name>



cd /path/to/local/repository
git add myfile.txt
git commit -m "added myfile.txt"
git push

--------
-- upload all files
git init    --> iz trenutno foldera u kojem se nalazimo
git add .
git commit -m "Added new files"
git push


--
 It s generally a good idea to pull changes from the 
 remote repository before pushing your own changes. 

 ---
 git pull

 ---
 -----------------------------for new commit
# Make changes to the file in your local repository
# ...

# Stage the changes for commit
$ git add myfile.txt

# Commit the changes with a descriptive message
$ git commit -m "Updated myfile.txt with new content"

# Push the changes to the remote repository
$ git push
--------------------------------------------
# Neue branch erstellen oder branch wechseln
git checkout -b <branchname>    

#branch wechseln:
git checkout 

#alle branches anschauen:
git branch
oder
git branch -a


#branch löschen:
git branch -D <zu-loeschende-branch>      --> force 
git branch -d <zu-loeschende-branch>       --> sichere

--
Wenn der zu löschende Branch auch auf dem Remote-Repository existiert und du ihn dort ebenfalls löschen möchtest,
-
git push origin --delete <zu-loeschende-branch>

------------------------



git reset ---> alle datei von "git add ."  zuruck rufen

------
git rm --cached classse.cpp
git commit -m "Stop tracking classse.cpp"


-----
----- want to megre one branch with another 

# Ensure you are on the branch where you want to merge changes (master)
git checkout master

# Merge changes from the tetris_one branch into master
git merge tetris_one

---------------


