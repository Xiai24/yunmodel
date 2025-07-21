<template>
  <div class="gpu-sidebar">
    <!-- 标签切换 -->
    <div class="tab-group">
      <button 
        v-for="(tab, index) in tabs" 
        :key="index" 
        :class="{ active: currentTab === tab }"
        @click="currentTab = tab"
      >
        {{ tab }}
      </button>
    </div>

    <!-- GPU 品牌筛选 -->
    <div class="filter-section">
      <h3 class="section-title">GPU 品牌</h3>
      <div class="tag-group">
        <button 
          v-for="(brand, index) in gpuBrands" 
          :key="index" 
          class="filter-btn"
          @click="handleBrandClick(brand)"
        >
          {{ brand }}
        </button>
      </div>
    </div>

    <!-- GPU 类型筛选 -->
    <div class="filter-section">
      <h3 class="section-title">GPU 类型</h3>
      <div class="tag-group">
        <button 
          v-for="(type, index) in gpuTypes" 
          :key="index" 
          class="filter-btn"
          @click="handleTypeClick(type)"
        >
          {{ type }}
        </button>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'

const tabs = ref(['容器', '裸金属'])
const currentTab = ref('容器')

const gpuBrands = ref([
  'Nvidia',
  '华为',
  '燧原'
])

const gpuTypes = ref([
  'A100-PCIE-40G',
  'A100-SXM4-80G',
  'A40-48G',
  'A800-PCIE-80GB',
  'Ascend-910B-64G',
  'Enflame-S60-48G',
  'H20-96G',
  'H200-141G',
  'L40S-48G',
  'RTX-3090-24G',
  'RTX-4090-24G',
  'RTX-4090-48G'
])

const handleBrandClick = (brand) => {
  console.log('点击了品牌：', brand)
}
const handleTypeClick = (type) => {
  console.log('点击了类型：', type)

}
</script>

<style scoped>
.gpu-sidebar {
  width: 220px;
  padding: 20px;
  border-right: 1px solid #e0e0e0;
  background-color: #fff;
}


.tab-group {
  display: flex;
  gap: 10px;
  margin-bottom: 20px;
}
.tab-group button {
  background: #e3f2fd;
  border: 1px solid #bbdefb; 
  color: #1565c0; 
  padding: 8px 16px;
  cursor: pointer;
  border-radius: 4px;
  transition: all 0.3s ease;
}
.tab-group button:hover {
  background: #bbdefb;
}
.tab-group button.active {
  background: #1976d2; 
  color: #fff; 
  border-color: #1976d2;
}


.filter-section {
  margin-bottom: 24px;
}
.section-title {
  font-size: 16px;
  font-weight: bold;
  margin-bottom: 12px;
  color: #333;
}

.tag-group {
  display: flex;
  flex-wrap: wrap;
  gap: 8px;
}
.filter-btn {
  background: #e3f2fd; 
  border: 1px solid #bbdefb; 
  color: #1565c0; 
  padding: 6px 12px;
  cursor: pointer;
  border-radius: 4px;
  transition: all 0.3s ease;
}
.filter-btn:hover {
  background: #bbdefb;
}

.filter-btn.active {
  background: #1976d2;
  color: #fff;
  border-color: #1976d2;
}
</style>