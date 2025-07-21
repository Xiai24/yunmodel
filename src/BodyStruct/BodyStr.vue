<template>
  <div class="layout">
    <el-container>
      <el-header class="head"><Header/></el-header>
      <el-container class="middle-container">
        <el-aside width="230px" class="aside"><RouterView name="side"></RouterView></el-aside>
        <el-container class="main-container">
          <el-main class="main"><RouterView name="main"></RouterView></el-main>
          <el-footer class="footer"><Footer/></el-footer>
        </el-container>
      </el-container>
    </el-container>
  </div>
</template>

<style scoped>
.layout {
  display: flex;
  flex-direction: column;
  min-height: 100vh;
}

.middle-container {
  flex: 1;
  display: flex;
}

.main-container {
  display: flex;
  flex-direction: column;
  flex: 1;
}


.footer {
  margin-top: 10%;  
  padding: 0;
  text-align: center;
  width: 100%;  
}

.aside {
  margin-top: 1%;
  text-align: center;
  border-top: 1px;
}
</style>

<script setup>
import Header from "../components/HeaderView.vue"
import Footer from "../components/FooterView.vue"
</script>