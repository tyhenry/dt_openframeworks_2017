# Setup


## 1. Download openFrameworks

Go to [openFrameworks.cc/download](http://openframeworks.cc/download/) and download the OF version that matches your platform (Mac, Windows, or Linux).  You'll download a zip file like `of_v0.9.8_osx_release.zip` to your computer.

Unzip this file. You'll see a folder like `of_v0.9.8_osx_release`, which contains everything you need to use openFrameworks. This folder will also be where you save your projects.  You can keep this folder anywhere on your hard drive, but I recommend placing it on your Desktop so it's easily accessible, i.e. `~/Desktop/of_v0.9.8_osx_release`.  You can also rename this folder to something nicer like `~/Desktop/openFrameworks` if you want.


## 2. Install your IDE

Your IDE - "integrated development environment" - is the software you will use to write and build your openFrameworks applications (an IDE is essentially a text editor combined with a compiler).

### macOS:
If you are on Mac, you should use **Xcode** as your IDE.  
[Follow these instructions](http://openframeworks.cc/setup/xcode/) on the openFrameworks website to get set up with Xcode.
_Note:_ The current version of Xcode is 8.3, and it requires that you have macOS Sierra (10.12), so you will need to upgrade your OS if you don't have Sierra.

### Windows:
On Windows, you'll use **Visual Studio Community 2015**.  [Follow these instructions](http://openframeworks.cc/setup/vs/) to get set up.

If you have any issues installing your IDE, e-mail me.


## 3. Setup Git, and clone the repositories

Git is the "version control" software we will use to keep track of our code, and share it with each other.  It's also how you'll submit your homework.  We will be using Git on the command line (i.e. through Terminal on a Mac).

Here's how to install Git:

### macOS:

On Mac, you'll want to install a package manager like [Homebrew](http://brew.sh/) first, then you can use the package manager to install Git and keep it up to date.

 1. **install Homebrew**  
    Open Terminal (Applications > Utilies > Terminal) and paste this:
    `/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`  
    and press return.  Homebrew will download and install itself.
 2. **then install Git**
	In Terminal type `brew install git`

### Windows:

On Windows, you should use the Git installer, downloaded directly from [the Git website](https://git-scm.com/download/win).  This will install Git on your computer, as well as Git Bash, which you will use as your command line interface to control Git.


## 5. Clone this repository

Go to your openFrameworks root directory in Terminal (or Git Bash on Windows). For instance, type:

	cd ~/Desktop/openFrameworks
	
(or replace `~/Desktop/openFrameworks/` with your openFrameworks folder path).

Now clone this repository:

	git clone https://github.com/tyhenry/dt_openframeworks_2017.git

You will see that the folder is downloaded next to the `apps/`, `libs/` and `addons/` folders

* ```addons/```
* ```apps/```
* ```libs/```
* ```examples/```
* ```scripts/```
* ```dt_openframeworks_2017/```

This folder structure will allow you to build the example applications in the `dt_openframeworks_2017` folder.


## 6. Create a GitHub account, and make a new repository for your homework

GitHub is the most popular website for sharing code.  You can access GitHub on the web at GitHub.com or through the command line using Git.  
Git + GitHub is the system we'll use to share example code, and it's how you'll submit homework.

* **Sign up:** You'll need to [sign up for a free account at GitHub.com](https://github.com/join) if you don't have one already.

* **Create repo:** Now create a repository for your homework on GitHub.com.
  **NAME IT AS FOLLOWS:** `[NewSchoolID]_dtOF_2017` (for example: `henrt555_dtOF_2017`)
  ![](github_create_repo.jpg)

* **Clone your new repo to your computer:**
  - Copy the repo address given to you by GitHub (e.g. `https://github.com/tyhenry/henrt555_dtOF_2017.git`)  
    ![](github_clone_link.jpg)
  - In Terminal (or Git Bash on Windows) navigate to your `openFrameworks/apps/` folder (e.g. type `cd ~/Desktop/openFrameworks/apps/`)
  - Now type `git clone ` and paste the address (e.g. `git clone https://github.com/tyhenry/henrt555_dtOF_2017.git`)

Now your homework repo folder should be setup inside `openFrameworks/apps/`. This is the folder where you will create your openFrameworks homework sketches using OF Project Generator.
You must organize your sketches by naming them as follows: ```[WEEK_NUMBER]_[HOMEWORK_NUMBER]_[NAME]```. 
For Example:

```
	openFrameworks/
		addons/
		app/
			henrt555_dtOF_2017/
				w01_h01_blahblah/
				w01_h02_helloworld/
				w02_h01_gototen/ 
				w03_h01_nandnor/ 
				etc…/
				…/
		libs/
		examples/
		dt_openframeworks_2017/
 ```


**Last Step: Add .gitignore file**
To keep your GitHub repo nice and neat, you need to add a `.gitignore` file that tells Git what files you don't want to track.
Copy the [.gitignore](../.gitignore) file from the `dt_openframeworks_2017` repo folder to your homework folder.

In Mac Finder or Windows Explorer you need to enable the **show hidden files** setting.

Or you can use the command line: 

```shell
	cd ~/Desktop/openFrameworks/apps/henrt555_dtOF_2017 
	cp ../../dt_openframeworks_2017/.gitignore .
```

