pipeline {
  agent any
  stages {
    stage('Build'){
      steps{
        echo "Building..."
        sh "make"
      }
    }
    stage('Running'){
      steps{
        echo "Running..."
        sh "./helloworld"
      }
    }
  }
}
