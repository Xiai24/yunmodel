<template>
  <div class="instance-purchase-container">
    <!-- 付费类型 -->
    <div class="pay-type">
      <el-radio-group v-model="payType">
        <el-radio label="prepay">
          <div class="radio-label">
            包年包月
            <span class="subtext">先付费后使用，价格优惠</span>
          </div>
        </el-radio>
        <el-radio label="postpay">
          <div class="radio-label">
            按量付费
            <span class="subtext">先使用后付费，按需开通</span>
          </div>
        </el-radio>
        <el-radio label="spot">
          <div class="radio-label">
            抢占式实例
            <span class="subtext">按按量计费，最高可省90%</span>
          </div>
        </el-radio>
      </el-radio-group>
    </div>

    <!-- 地域 & 网络 -->
    <div class="region-network">
      <div class="form-item">
        <label>地域</label>
        <el-select v-model="region" placeholder="选择地域">
          <el-option label="华北（北京）" value="beijing"></el-option>
          <el-option label="华东（杭州）" value="hangzhou"></el-option>
          <el-option label="华南（广州）" value="guangzhou"></el-option>
          <el-option label="中国香港" value="hongkong"></el-option>
        </el-select>
      </div>
      <div class="form-item">
        <label>网络及可用区</label>
        <el-select v-model="zone" placeholder="选择可用区">
          <el-option label="默认专有网络" value="vpc-default"></el-option>
          <el-option label="随机分配可用区" value="zone-random"></el-option>
        </el-select>
      </div>
    </div>

    <!-- 实例和镜像筛选 -->
    <div class="instance-filter">
      <div class="filter-tabs">
        <el-button
          v-for="(tab, index) in filterTabs"
          :key="index"
          :class="{ active: currentFilterTab === tab }"
          @click="currentFilterTab = tab"
        >
          {{ tab }}
        </el-button>
      </div>
      <div class="filter-section">
        <label>架构：</label>
        <el-select v-model="architecture" placeholder="选择架构">
          <el-option label="X86 计算" value="x86"></el-option>
          <el-option label="Arm 计算" value="arm"></el-option>
          <el-option label="GPU/FPGA/ASIC" value="gpu"></el-option>
        </el-select>
        <label>类型：</label>
        <el-select v-model="instanceType" placeholder="选择类型">
          <el-option label="计算型" value="compute"></el-option>
          <el-option label="通用型" value="general"></el-option>
          <el-option label="内存型" value="memory"></el-option>
        </el-select>
        <el-input
          v-model="keyword"
          placeholder="模糊搜索实例规格"
          clearable
          class="search-input"
        />
        <el-button type="primary" icon="Search">搜索</el-button>
      </div>
    </div>

    <!-- 实例列表 -->
    <div class="instance-list">
      <el-table
        :data="instanceData"
        border
        style="width: 100%"
        :header-cell-style="{ background: '#e3f2fd', color: '#666' }"
      >
        <el-table-column
          prop="name"
          label="规格族"
          min-width="120"
        />
        <el-table-column
          prop="type"
          label="实例规格"
          min-width="120"
        />
        <el-table-column
          prop="vcpus"
          label="vCPU"
          min-width="80"
        />
        <el-table-column
          prop="memory"
          label="内存"
          min-width="80"
        />
        <el-table-column
          prop="zones"
          label="可用区"
          min-width="100"
        />
        <el-table-column
          prop="price"
          label="参考价格"
          min-width="120"
        />
      </el-table>
      <el-pagination
        @size-change="handleSizeChange"
        @current-change="handleCurrentChange"
        :current-page="currentPage"
        :page-sizes="[10, 20, 50]"
        :page-size="pageSize"
        layout="total, sizes, prev, pager, next, jumper"
        :total="total"
        class="pagination"
      />
    </div>

    <!-- 镜像选择 -->
    <div class="image-section">
      <h3>镜像</h3>
      <el-input
        v-model="imageSearch"
        placeholder="搜索镜像（如 Ubuntu）"
        clearable
        class="image-search"
      />
      <el-button type="primary" icon="Search">搜索目录</el-button>
      <div class="image-tabs">
        <el-button
          v-for="(tab, index) in imageTabs"
          :key="index"
          :class="{ active: currentImageTab === tab }"
          @click="currentImageTab = tab"
        >
          {{ tab }}
        </el-button>
      </div>
      <div class="image-list">
        <el-button
          v-for="(image, index) in imageData"
          :key="index"
          :class="{ 'image-btn': true, active: selectedImage === image }"
          @click="selectedImage = image"
        >
          {{ image }}
        </el-button>
      </div>
    </div>

    <!-- 扩展配置 -->
    <div class="extension-section">
      <h3>扩展配置</h3>
      <el-checkbox v-model="enableMonitor">开启云监控</el-checkbox>
      <el-checkbox v-model="enableHibernation">开启冬眠</el-checkbox>
    </div>
  </div>
</template>

<script setup>
import { ref } from 'vue'

// 付费类型
const payType = ref('prepay')

// 地域 & 网络
const region = ref('hangzhou')
const zone = ref('vpc-default')

// 实例筛选
const filterTabs = ref(['全部规格', 'ECS 实例规格族助手'])
const currentFilterTab = ref('全部规格')
const architecture = ref('x86')
const instanceType = ref('compute')
const keyword = ref('')
const instanceData = ref([
  { name: '计算型 c6i', type: 'ecs.c6.large', vcpus: '2 vCPU', memory: '4.0 GiB', zones: '18个可用区', price: '¥185.97/月' },
  { name: '计算型 c6i', type: 'ecs.c6.xlarge', vcpus: '4 vCPU', memory: '8.0 GiB', zones: '17个可用区', price: '¥371.82/月' },
  { name: '通用型 g6i', type: 'ecs.g6.large', vcpus: '2 vCPU', memory: '8.0 GiB', zones: '17个可用区', price: '¥238.6/月' },
  { name: '经济型 e', type: 'ecs.e-c1m2.xlarge', vcpus: '8 vCPU', memory: '16.0 GiB', zones: '68个可用区', price: '¥4820/月' },
  { name: '内存型 r6i', type: 'ecs.r6.large', vcpus: '2 vCPU', memory: '16.0 GiB', zones: '20个可用区', price: '¥320.5/月' },
  { name: 'GPU 型 gn6', type: 'ecs.gn6.large', vcpus: '4 vCPU', memory: '32.0 GiB', zones: '10个可用区', price: '¥1280/月' },
])
const currentPage = ref(1)
const pageSize = ref(10)
const total = ref(50)

// 镜像选择
const imageSearch = ref('')
const imageTabs = ref(['公共镜像', '自定义镜像', '共享镜像', '云市场镜像', '社区镜像'])
const currentImageTab = ref('公共镜像')
const imageData = ref([
  'Alibaba Cloud Linux', 'Anolis OS', 'CentOS', 'Windows Server', 'SUSE Linux', 'Ubuntu', 'Red Hat',
])
const selectedImage = ref('Alibaba Cloud Linux')

// 扩展配置
const enableMonitor = ref(true)
const enableHibernation = ref(false)

// 分页事件
const handleSizeChange = (val) => {
  pageSize.value = val
  // 调用接口刷新数据
}
const handleCurrentChange = (val) => {
  currentPage.value = val
  // 调用接口刷新数据
}
</script>

<style scoped>
.instance-purchase-container {
  padding: 20px;
  background-color: #f9f9f9;
  min-height: 100vh;
}

/* 付费类型 */
.pay-type {
  margin-bottom: 20px;
}
.radio-label {
  display: flex;
  flex-direction: column;
}
.subtext {
  font-size: 12px;
  color: #999;
}

/* 地域 & 网络 */
.region-network {
  display: flex;
  gap: 20px;
  margin-bottom: 20px;
}
.form-item {
  display: flex;
  flex-direction: column;
}
.form-item label {
  margin-bottom: 5px;
  color: #666;
}

/* 实例筛选 */
.filter-tabs {
  margin-bottom: 10px;
}
.filter-tabs .el-button {
  background: #e3f2fd;
  border: 1px solid #bbdefb;
  color: #1565c0;
  margin-right: 10px;
}
.filter-tabs .el-button.active {
  background: #1976d2;
  color: #fff;
}
.filter-section {
  display: flex;
  gap: 10px;
  align-items: center;
  margin-bottom: 20px;
}
.search-input {
  width: 200px;
}

/* 实例列表 */
.instance-list {
  margin-bottom: 20px;
}
.el-table th {
  background-color: #e3f2fd !important;
}
.pagination {
  margin-top: 10px;
  text-align: right;
}

/* 镜像选择 */
.image-section {
  margin-bottom: 20px;
}
.image-tabs {
  margin: 10px 0;
}
.image-tabs .el-button {
  background: #e3f2fd;
  border: 1px solid #bbdefb;
  color: #1565c0;
  margin-right: 10px;
}
.image-tabs .el-button.active {
  background: #1976d2;
  color: #fff;
}
.image-list {
  display: flex;
  flex-wrap: wrap;
  gap: 10px;
}
.image-btn {
  background: #e3f2fd;
  border: 1px solid #bbdefb;
  color: #1565c0;
}
.image-btn.active {
  background: #1976d2;
  color: #fff;
}

/* 扩展配置 */
.extension-section {
  margin-bottom: 20px;
}
</style>