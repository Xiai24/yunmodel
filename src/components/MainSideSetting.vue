<template>
  <el-menu
    default-active="1"
    class="side-nav"
    :collapse="isCollapse"
    :background-color="backgroundColor"
    :text-color="textColor"
    :active-text-color="activeTextColor"
    router
  >
    <el-menu-item index="/">
      <template #title>主页</template>
    </el-menu-item>

    <el-menu-item index="/detail">
      <template #title>容器实例</template>
    </el-menu-item>

    <el-menu-item>
      <template #title>裸金属实例</template>
    </el-menu-item>

    <el-menu-item>
      <template #title>镜像管理</template>
    </el-menu-item>

    <el-menu-item>
      <template #title>文件管理</template>
    </el-menu-item>

    <el-sub-menu>
      <template #title>
        <span>网络管理</span>
      </template>
      <el-menu-item>网络配置</el-menu-item>
      <el-menu-item>网络监控</el-menu-item>
    </el-sub-menu>

    <el-sub-menu>
      <template #title>
        <span>费用中心</span>
      </template>
      <el-menu-item>账单查询</el-menu-item>
      <el-menu-item>费用概览</el-menu-item>
    </el-sub-menu>

    <el-sub-menu>
      <template #title>
        <span>账户中心</span>
      </template>
      <el-menu-item>个人资料</el-menu-item>
      <el-menu-item>安全设置</el-menu-item>
    </el-sub-menu>

    <el-menu-item>
      <template #title>工单</template>
    </el-menu-item>
  </el-menu>
</template>

<script setup>
import { ref } from 'vue'

const isCollapse = ref(false) 
const backgroundColor = ref('#e3f2fd') 
const textColor = ref('#666')  
const activeTextColor = ref('#1976d2') 
</script>

<style scoped>
.side-nav {
  width: 220px;
  border-right: none; 
  background-color: #e3f2fd !important;
}

 
.el-menu-item,
.el-sub-menu__title {
  padding-left: 20px !important;
  font-size: 14px;
  color: #666;  
}
 
.el-sub-menu .el-menu {
  background-color: #e3f2fd !important;  
}

 
.el-icon {
  margin-right: 8px;
  color: #1976d2;  
}

 
.el-menu-item.is-active {
  background-color: #bbdefb !important;  
  color: #1976d2 !important;  
}

 
.el-menu-item:hover,
.el-sub-menu__title:hover {
  background-color: #bbdefb !important;  
  color: #1976d2 !important;  
}
</style>