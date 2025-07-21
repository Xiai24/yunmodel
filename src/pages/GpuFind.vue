<template>
  <div class="gpu-list-container">
    <!-- GPU 卡片网格 -->
    <div class="card-grid">
      <div 
        class="gpu-card" 
        v-for="(gpu, index) in gpuData" 
        :key="index"
      >
        <div class="card-header">
          <h2 class="gpu-model">{{ gpu.model }}</h2>
          <p class="region">{{ gpu.region }}</p>
        </div>
        <div class="specs">
          <p><strong>显存：</strong>{{ gpu.memory }}</p>
          <p><strong>CPU：</strong>{{ gpu.cpu }}</p>
          <p><strong>内存：</strong>{{ gpu.ram }}</p>
        </div>
        <div class="price">
          <p>会员低至</p>
          <p class="price-value">¥{{ gpu.price }}/小时</p>
        </div>
        <router-link to="/create" class="rent-btn">
          立即租用
        </router-link>
      </div>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'

// 模拟 GPU 数据
const gpuData = ref([
  {
    model: 'RTX-3090-24G',
    region: '西北一区',
    memory: '24 GB',
    cpu: '16核 | Intel(R) Xeon(R) Platinum 8358P',
    ram: '96GB',
    price: 1.33
  },
  {
    model: 'RTX-4090-24G',
    region: '西北一区',
    memory: '24 GB',
    cpu: '16核 | AMD EPYC 7542',
    ram: '128GB',
    price: 1.96
  },
  {
    model: 'RTX-4090-24G',
    region: '华东三区',
    memory: '24 GB',
    cpu: '16核 | AMD EPYC 7542',
    ram: '64GB',
    price: 1.96
  },
  {
    model: 'RTX-A5000-24G',
    region: '西北一区',
    memory: '24 GB',
    cpu: '16核 | AMD EPYC 7542',
    ram: '128GB',
    price: 0.79
  },
  {
    model: 'RTX-4090-24G',
    region: '华东三区',
    memory: '24 GB',
    cpu: '16核 | AMD EPYC 7542',
    ram: '60GB',
    price: 1.96
  },
  {
    model: 'A800-PCIE-80GB',
    region: '西南一区',
    memory: '80 GB',
    cpu: '12核 | Intel(R) Xeon(R) Gold 6442Y',
    ram: '128GB',
    price: 5.65
  },
  {
    model: 'A100-PCIE-40G',
    region: '西北一区',
    memory: '40 GB',
    cpu: '16核 | AMD EPYC 7542',
    ram: '128GB',
    price: 3.11
  },
  {
    model: 'Ascend-910B-64G',
    region: '国产专区',
    memory: '64 GB',
    cpu: '24核 | HiSilicon Kunpeng-920',
    ram: '128GB',
    price: 3.47
  }
])
</script>

<style scoped>
/* 容器样式 */
.gpu-list-container {
  font-family: Arial, sans-serif;
  padding: 20px;
  background-color: #eaf6fc; /* 淡蓝色背景，营造整体淡蓝氛围 */
}

/* GPU 卡片网格 */
.card-grid {
  display: grid;
  grid-template-columns: repeat(auto-fit, minmax(300px, 1fr));
  gap: 20px;
}

/* GPU 卡片 */
.gpu-card {
  background: #fff;
  border: 1px solid #bde0f5; /* 淡蓝色边框，和整体主题呼应 */
  border-radius: 8px;
  padding: 16px;
  box-shadow: 0 2px 4px rgba(0, 0, 0, 0.05);
  transition: all 0.3s ease;
}

.gpu-card:hover {
  transform: translateY(-5px);
  box-shadow: 0 4px 8px rgba(189, 224, 245, 0.5); /* 淡蓝色阴影，hover 更协调 */
}

.card-header {
  margin-bottom: 12px;
}

.gpu-model {
  font-size: 18px;
  margin-bottom: 4px;
  color: #3498db; /* 淡蓝色标题文字色 */
}

.region {
  color: #95a5a6; /* 浅灰色文字，辅助说明 */
  font-size: 14px;
}

.specs p {
  margin: 4px 0;
  color: #555; /* 稍深灰色，保证可读性 */
}

.price {
  margin: 12px 0;
  color: #2980b9; /* 稍深的淡蓝色，突出价格相关 */
}

.price-value {
  font-size: 16px;
  font-weight: bold;
}

/* 立即租用按钮 */
.rent-btn {
  display: inline-block;
  background: #3498db; /* 淡蓝色按钮背景 */
  color: #fff;
  padding: 10px 20px;
  text-decoration: none;
  border-radius: 4px;
  text-align: center;
  margin-top: 10px;
  transition: all 0.3s ease;
}

.rent-btn:hover {
  background: #2980b9; /* 加深的淡蓝色，hover 反馈 */
}
</style>